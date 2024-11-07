/*
 * 2024-11-01
 * graph theory
 *
 * 图的存法：邻接表、邻接矩阵、边集数组、*链式前向星*
 *  链式前向星为主要学的
 *
 * 拓扑排序问题
 * 欧拉路
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <iomanip>
#include<string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <set>
#include <stdio.h>

using namespace std;


const int N = 1e6 + 2, M = 2e6 + 2;
int head[N], cnt = 0;

struct {
    int from, to, next;
    int weight; // depend on the needs
} edge[M];

void init(int n, int m) {
    for (int i = 0; i <= n; ++i)
        head[i] = -1;
    for (int i = 0; i <= m; i++)
        edge[i].next -1;
    cnt = 0;
}

void addEdge(int u, int v, int w) {
    edge[cnt].from = u;
    edge[cnt].to = v;
    edge[cnt].weight = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}


int main() {


    int n, m;
    cin >> n >> m;
    init(n, m);
    int u, v, w;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }
    for(int i = 0; i <= n; i++) {
        printf("h[ %d ]= %d,", i, head[i]);
    }
    cout << endl;
    for(int i = 0; i < m; i++) {
        printf("e[ %d ].to= %d,", i, edge[i].to);
    }
    cout << endl;
    for(int i = 0; i < m; i++) {
        printf("e[ %d ].from= %d, ", i, edge[i].from);
    }
    cout << endl;
    for(int i = 0; i < m; i++) {
        printf("e[ %d ].next = %d, ", i, edge[i].next);
    }
    cout << endl;
    for(int i = head[2]; ~i; i = edge[i].next) {
        printf("%d  ", edge[i].to);
    }
    cout << endl;
    return 0;
}
