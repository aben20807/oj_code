// 注意是找最"大"生成樹的最"小"邊
// 排序由大到小，最後一個 Union 的邊就是最小

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct edge {
    int u;
    int v;
    int c;
};

int sset[110];

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

bool cmp(struct edge a, struct edge b)
{
    return a.c > b.c;
}

int main()
{
    int t, casecnt = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        struct edge e[m];
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].c);
        }
        /* init */
        for (int i = 0; i < n; i++) {
            sset[i] = i;
        }
        /* Kruskal */
        sort(e, e + m, cmp);
        int ans = 0;
        for (int i = 0, edgenum = 0; i < m; i++) {
            if (Union(e[i])) {
                ans = e[i].c;
                edgenum++;
            }
            if (edgenum == n - 1)
                break;
        }
        printf("Case #%d: %d\n", casecnt++, ans);
    }
    return 0;
}
