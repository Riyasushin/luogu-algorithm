#include <iostream>
#include <iomanip>
#include<string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <set>

using namespace std;

const int N = 20005;
int sets[N];
int d[N];
int res = 0;

void init(int n) {
    for (int i = 0; i <= n; i++) {
        sets[i] = i;
        d[i] = 0;
    }
}

int findroot(int x) {
    if (x != sets[x]) {
        int temp = sets[x];
        sets[x] = findroot(sets[x]);
        /// !!!
        d[x] = (d[x] + d[temp] + 2) % 2;
    }
    return sets[x];
}

void merge_set(int x, int y, int rootx, int rooty) {

    sets[rootx] = rooty;
    d[rootx] = (d[y] + 1 - d[x]) % 2;
}

struct opps {
    int x, y, conflect;
    bool operator<(const opps& b) const {
        return conflect > b.conflect;
    }
}pairs[1000005];

int main() {

    int n, m;
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; i++){
        int x, y, c;
        cin >> x >> y >> c;
        pairs[i] = {x, y, c};
    }
    sort(pairs, pairs + m);
    int res = 0;
    for (int i = 0; i < m; i++) {
        int x1 = pairs[i].x, y1 = pairs[i].y, conf = pairs[i].conflect;
        int rx = findroot(x1), ry = findroot(y1);
        if (rx == ry && d[x1] == d[y1]) {
            res = conf;
            break;
        } else {
            merge_set(x1, y1, rx, ry);
        }
    }
    cout <<res <<endl;


    return 0;
}
