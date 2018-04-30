// 走一步+1找最長路徑改成走一步-1找最短路徑
// 利用 Bellman Ford

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define INF 1e9

struct edge {
    int A;
    int B;
} w[10010];

int dis[10010];
int edgenum;

bool relax(struct edge e)
{
    int x = e.A;
    int y = e.B;
    if (dis[x] - 1 < dis[y]) {
        dis[y] = dis[x] - 1;
        return true;
    }
    return false;
}

void bellmanford(int n)
{
    for (int i = 0; i < n - 1; i++) {
        bool change = false;
        for (int j = 0; j < edgenum; j++) {
            if (relax(w[j]))
                change = true;
        }
        if (!change)
            return;
    }
}

int main()
{
    int n, casecnt = 1;
    while (scanf("%d", &n) && n) {
        edgenum = 0;
        int s;
        scanf("%d", &s);
        int A, B;
        while (scanf("%d%d", &A, &B)) {
            if (A == 0 && B == 0) {
                break;
            } else {
                w[edgenum].A = A;
                w[edgenum].B = B;
                edgenum++;
            }
        }
        /* init */
        for (int i = 1; i <= n; i++) {
            dis[i] = INF;
        }
        dis[s] = 0;
        bellmanford(n);
        int mmax = 0, pos = 0;
        for (int i = 1; i <= n; i++) {
            if (mmax < (-1) * dis[i]) {
                mmax = (-1) * dis[i];
                pos = i;
            }
        }
        printf("Case %d: The longest path from %d ", casecnt++, s);
        printf("has length %d, finishing at %d.\n\n", mmax, pos);
    }
    return 0;
}
