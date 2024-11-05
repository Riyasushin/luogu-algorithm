#include <iostream>
#include <iomanip>
#include<string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <set>

using namespace std;

const int N = 50005;
int sets[N];
int d[N];
int res = 0;

void init(int n) {
    for (int i = 0; i <= n; i++) {
        sets[i] = i;
        d[i] = 0;
    }
}

int findreoot(int x) {
    if (x != sets[x]) {
        int temp = sets[x];
        sets[x] = findreoot(sets[x]);
        /// !!!
        d[x] = (d[x] + d[temp] + 3) % 3;
    }
    return sets[x];
}

void merge_set(int x, int y, int D) {
    int rootx = findreoot(x), rooty = findreoot(y);
    if (rootx == rooty) {
        /// already have relations,check
        // if (d == 1 && d[x] - d[y] != 0) {
        //     res++;
        // } else if (d == 2 && d[x] - d[y] != 1){
        //     res++;
        // }
        if ((D - 1) != (d[x] - d[y] + 3) % 3)
            res++;
    } else {
        sets[rootx] = rooty;
        if (D == 1) {
            d[rootx] = (d[y] - d[x] + 3) % 3;
        } else {
            d[rootx] = (d[y] - d[x] + 1 + 3) % 3;
        }
    }
}

int main() {

    int n, k;
    cin >> n >> k;
    init(n);
    while (k--) {
        int D, x, y;
        cin >> D >> x >> y;
        if( x > n || y > n || (D == 2 && x == y))
            res++;
        else {
            merge_set(x, y, D);
        }
    }

    cout << res << endl;

    return 0;
}
