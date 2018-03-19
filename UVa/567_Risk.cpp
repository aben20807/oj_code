#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int vis[21];
int dis[21];

void bfs(int i, int j, map<int, vector<int>> adj)
{
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == j)
            return;
        // printf("size: %d\n", (int)adj[cur].size());
        for (int x = 0; x < (int)adj[cur].size(); x++) {
            int nxt = adj[cur][x];
            if (!vis[nxt]) {
                dis[nxt] = dis[cur] + 1;
                vis[nxt] = 1;
                q.push(nxt);
            }
        }
    }
    return;
}

int main()
{
    int n1;
    int casecnt = 1;
    while (scanf("%d", &n1) != EOF) {
        map<int, vector<int>> adj;
        while (n1--) {
            int tmp;
            scanf("%d", &tmp);
            adj[1].push_back(tmp);
            adj[tmp].push_back(1);
        }
        for (int i = 2; i <= 19; i++) {
            int nn;
            scanf("%d", &nn);
            while (nn--) {
                int tmp;
                scanf("%d", &tmp);
                adj[i].push_back(tmp);
                adj[tmp].push_back(i);
            }
        }
        int testn;
        printf("Test Set #%d\n", casecnt++);
        scanf("%d", &testn);
        while (testn--) {
            int i, j;
            scanf("%d%d", &i, &j);
            printf("%2d to %2d: ", i, j);
            memset(dis, 0, sizeof(dis));
            memset(vis, 0, sizeof(vis));
            bfs(i, j, adj);
            printf("%d\n", dis[j]);
        }
        printf("\n");
    }
    return 0;
}
