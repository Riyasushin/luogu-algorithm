#include <iostream>
#include <iomanip>
#include<string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <set>

using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
int sets[N], b[N<<2];

bool hasCrash = false;

inline int read()
{
    int f = 1,x = 0;
    char ch=getchar();
    while (ch < '0' || ch > '9') {
        if(ch == '-') f=-1;
        ch=getchar();
    }
    while(ch<='9'&&ch>='0') {
        x=x*10+ch-'0',ch=getchar();
    }
    return f*x;
}

void init(int n) {
    for (int i = 0; i <= n; i++) {
        sets[i] = i;
    }
}
int findroot(int x) {
    if (x != sets[x]) {
        sets[x] = findroot(sets[x]);
    }
    return sets[x];
}

struct node{
    int x,y,e;

    bool operator< (const node& b) const {
        return e > b.e;
    }
}arr[N];

int main() {

    int trials;
    trials = read();
    while (trials--) {

        memset(arr,0,sizeof(arr));
        memset(b,0,sizeof(b));
        memset(sets,0,sizeof(sets));

        int n;
        n = read();

        int tot = 0;

        for (int x = 1; x <= n; ++x){
            int i, j, e;
            i = read(), j = read(), e = read();
            arr[x] = {i, j, e};
            b[++tot] = i;
            b[++tot] = j;
        }

        sort(b + 1, b + 1 + tot);
        int tott = unique(b+1,b+1+tot)-b;
        for (int i = 1; i <= n; ++i) {
            arr[i].x = lower_bound(b + 1, b + 1 + tott, arr[i].x) - b;
            arr[i].y = lower_bound(b + 1, b + 1 + tott, arr[i].y) - b;
        }
        sort(arr + 1, arr + 1 + n);
        init(tott + 1);


        hasCrash = false;
        for (int op = 1; op <= n; ++op) {

            int rooti = findroot(arr[op].x);
            int rootj = findroot(arr[op].y);
            if (arr[op].e == 1) {

                if (rooti != rootj) {
                    sets[rooti] = rootj;
                }
            } else {
                if (rooti == rootj) {
                    hasCrash = true;
                    break;
                }
            }
        }


        if (hasCrash)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}


