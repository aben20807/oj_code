#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

#define INF 1e9

struct edge {
    int A;
    int B;
    int delay;
} w[100];
int dis[12];
int pre[12];
int edgenum;

bool relax(struct edge e)
{
    int x = e.A;
    int y = e.B;
    if (dis[x] + e.delay < dis[y]) {
        dis[y] = dis[x] + e.delay;
        pre[y] = x;
        return true;
    }
    return false;
}

void bellmanford(int NI)
{
    for (int i = 0; i < NI - 1; i++) {
        bool change = false;
        for (int j = 0; j < edgenum; j++)
            if (relax(w[j]))
                change = true;
        if (!change)
            return;
    }
}

int main()
{
    int NI, casecnt = 1;
    while (scanf("%d", &NI) && NI) {
        edgenum = 0;
        for (int i = 1; i <= NI; i++) {
            int n;
            scanf("%d", &n);
            for (int j = 0; j < n; j++) {
                scanf("%d%d", &w[edgenum].B, &w[edgenum].delay);
                w[edgenum++].A = i;
            }
        }
        int F, T;
        scanf("%d%d", &F, &T);
        /* init */
        for (int i = 1; i <= NI; i++) {
            dis[i] = INF;
            pre[i] = 0;
        }
        dis[F] = 0;
        bellmanford(NI);
        vector<int> ans;
        int cur = T;
        while (cur != F) {
            cur = pre[cur];
            ans.push_back(cur);
        }
        printf("Case %d: Path =", casecnt++);
        for (int i = ans.size() - 1; i >= 0; i--) {
            printf(" %d", ans[i]);
        }
        printf(" %d; %d second delay\n", T, dis[T]);
    }
    return 0;
}
