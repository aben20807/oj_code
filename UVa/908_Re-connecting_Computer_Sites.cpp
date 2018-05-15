// 一開始 n-1 個邊要算距離直接把 cost 加總即可
// 接著把 k + m 邊跑 Kruskal 找出 MST，並找出新的總長
// 記得每個 case 要用換行間隔

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
    int u;
    int v;
    int c;
};

int sset[1000010];

bool cmp(struct edge a, struct edge b)
{
    return a.c < b.c;
}

int Find(int x)
{
    if (x == sset[x])
        return x;
    return sset[x] = Find(sset[x]);
}

bool Union(struct edge e)
{
    int x = Find(e.u);
    int y = Find(e.v);
    if (x != y) {
        sset[x] = y;
        return true;
    }
    return false;
}

int main()
{
    int n, isfirst = 1;
    while (~scanf("%d", &n)) {
        if (isfirst == 0)
            printf("\n");
        isfirst = 0;
        int orilen = 0;
        for (int i = 0, u, v, c; i < n - 1; i++) {
            scanf("%d%d%d", &u, &v, &c);
            orilen += c;
        }
        printf("%d\n", orilen);
        vector<struct edge> e;
        int k;
        scanf("%d", &k);
        for (int i = 0, u, v, c; i < k; i++) {
            scanf("%d%d%d", &u, &v, &c);
            e.push_back({u, v, c});
        }
        int m;
        scanf("%d", &m);
        for (int i = 0, u, v, c; i < m; i++) {
            scanf("%d%d%d", &u, &v, &c);
            e.push_back({u, v, c});
        }
        /* init */
        for (int i = 0; i <= n; i++) {
            sset[i] = i;
        }
        /* Kruskal */
        sort(e.begin(), e.end(), cmp);
        int newlen = 0;
        for (int i = 0, edgenum = 0; i < (int)e.size(); i++) {
            if (Union(e[i])) {
                newlen += e[i].c;
                edgenum++;
            }
            if (edgenum == n - 1)
                break;
        }
        printf("%d\n", newlen);
    }
    return 0;
}
