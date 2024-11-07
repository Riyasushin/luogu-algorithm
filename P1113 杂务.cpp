/*
 * 2024-11-01
 * graph theory
 *
 * 图的存法：*链式前向星*
 * 思路，贪心，尽可能的速度，因此想到dp
 *
 * 这里是有向无环图（树）
 * 怎么枚举？？？？
 * 存法的改变，简单来说，倒着存 a -> b 存为 a <- b 方便进行拓扑排序
 *
 *
 */

#include <iostream>
#include <iomanip>
#include<string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <stdio.h>

using namespace std;

const int N = 1e4 + 2, M = 1e6 + 2;

int dp[N] = {};
int timec[N] = {};
int indegree[N] = {};

int head[N];
struct {
    int from, to, next;
} edge[M] = {};

int cnt = 0;
void addEdge(int u, int v) {
    edge[++cnt].from = v;
    edge[cnt].to = u;
    edge[cnt].next = head[v];
    head[v] = cnt;
}

int main() {

    int n;
    cin >> n;

    // init
    cnt = 0;
    for (int i = 0; i <= n; ++i) {
        indegree[i] = 0;
    }

    // make graph
    for (int i = 1; i <= n; ++i) {
        int id, need;
        cin >> id >> timec[i];
        dp[id] = timec[i];
        while (cin >> need) {
            if (need == 0)
                break;
            addEdge(id, need);
            indegree[id]++;
        }

    }

    //  do search - dp
    queue<int> nofoll;
    for (int i = 1; i <= n; ++i) {
        if(indegree[i] == 0)
            nofoll.push(i);
    }

    int res = 0;
    while (!nofoll.empty()) {
        int hea = nofoll.front();
        nofoll.pop();

        for (int i = head[hea]; i > 0; i = edge[i].next) {
            indegree[edge[i].to]--;
            if (indegree[edge[i].to] == 0)
                nofoll.push(edge[i].to);

            dp[edge[i].to] = max(dp[edge[i].to], dp[hea] + timec[edge[i].to]);
            res = max(res, dp[edge[i].to]);
        }


    }

    cout << res << endl;


    // for (int i = head[1]; i > 0; i = edge[i].next) {
    //     printf("%d ", edge[i].to);
    // }

}
