// 用 Bellman Ford 找完最短路徑後
// 再 relax 若還有改變(還有更短的路徑)代表有負環產生

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define INF 1e9

struct edge {
    int A;
    int B;
    int dis;
} w[2010];

int n, m;
int dis[1010];

bool relax(struct edge e)
{
    int x = e.A;
    int y = e.B;
    if (dis[x] + e.dis < dis[y]) {
        dis[y] = dis[x] + e.dis;
        return true;
    }
    return false;
}

void bellmanford(int NI)
{
    for (int i = 0; i < NI - 1; i++) {
        bool change = false;
        for (int j = 0; j < m; j++)
            if (relax(w[j]))
                change = true;
        if (!change)
            return;
    }
}


int main()
{
    int t;
    while (~scanf("%d", &t)) {
        while (t--) {
            scanf("%d%d", &n, &m);
            for (int i = 0; i < m; i++) {
                scanf("%d%d%d", &(w[i].A), &(w[i].B), &(w[i].dis));
            }
            /* init */
            for (int i = 1; i < n; i++) {
                dis[i] = INF;
            }
            dis[0] = 0;
            bellmanford(n);
            bool change = false;
            for (int j = 0; j < m; j++)
                if (relax(w[j]))
                    change = true;
            if (!change) {
                printf("not possible\n");
            } else {
                printf("possible\n");
            }
        }
    }
    return 0;
}
