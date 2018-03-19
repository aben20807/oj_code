#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n, m;
int edge[26][26];
int dis[26];
int maxstep;

void dfs(int i, int d)
{
    for (int x = 0; x < n; x++) {
        if (edge[i][x]) {
            if (maxstep < d)
                maxstep = d;
            // printf("%d->%d: %d\n", i, x, d);
            edge[i][x] = 0;
            edge[x][i] = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // printf("%d", edge[i][j]);
                }
                // printf("\n");
            }
            // printf("----------------\n");
            // d++;
            dis[x] = dis[i] + 1;
            dfs(x, d + 1);
            edge[i][x] = 1;
            edge[x][i] = 1;
        }
    }
}

int main()
{
    while (scanf("%d%d", &n, &m)) {
        if (n == 0 && m == 0)
            break;
        memset(edge, 0, sizeof(edge));
        while (m--) {
            int i, j;
            scanf("%d%d", &i, &j);
            edge[i][j] = 1;
            edge[j][i] = 1;
        }
        // for (int i = 0; i < n; i++){
        // for (int j = 0; j < n; j++){
        // printf("%d", edge[i][j]);
        // }
        // printf("\n");
        // }
        // memset(dis, 0, sizeof(dis));
        int maxmaxstep = 0;
        for (int i = 0; i < n; i++) {
            memset(dis, 0, sizeof(dis));
            maxstep = 0;
            int d = 1;
            dfs(i, d);
            for (int j = 0; j < n; j++) {
                // printf("%d ", dis[j]);
            }
            if (maxmaxstep < maxstep)
                maxmaxstep = maxstep;
            // printf("\n");
        }
        printf("%d\n", maxmaxstep);
    }
    return 0;
}
