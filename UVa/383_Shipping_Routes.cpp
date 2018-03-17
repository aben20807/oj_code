#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int bfs(string from, string to, map<string, vector<string>> adj)
{
    map<string, int> vis, dis;
    queue<string> q;
    q.push(from);
    vis[from] = 1;
    dis[from] = 0;
    while (!q.empty()) {
        string cur = q.front();
        if (cur == to) {
            // printf("%d\n", dis[cur]);
            return dis[cur];
        }
        q.pop();
        for (int i = 0; i < (int)adj[cur].size(); i++) {
            string next = adj[cur][i];
            if (vis[next] != 1) {
                vis[next] = 1;
                q.push(next);
                dis[next] = dis[cur] + 1;
            }
        }
    }
    return -1;
}

int main()
{
    int ds, cnt = 1;
    while (scanf("%d", &ds) != EOF) {
        printf("SHIPPING ROUTES OUTPUT\n\n");
        while (ds--) {
            printf("DATA SET  %d\n\n", cnt++);
            int m, n, p;
            scanf("%d%d%d", &m, &n, &p);
            map<string, vector<string>> adj;
            string warehouse[m];
            for (int i = 0; i < m; i++) {
                cin >> warehouse[i];
            }
            for (int i = 0; i < n; i++) {
                string w1, w2;
                cin >> w1 >> w2;
                adj[w1].push_back(w2);
                adj[w2].push_back(w1);
            }
            for (int i = 0; i < p; i++) {
                int price;
                scanf("%d", &price);
                string from, to;
                cin >> from >> to;
                int step = bfs(from, to, adj);
                // printf("%s %s %d\n", from.c_str(), to.c_str(), step);
                if (step != -1)
                    printf("$%d\n", step * price * 100);
                else
                    printf("NO SHIPMENT POSSIBLE\n");
            }
            printf("\n");
        }
        printf("END OF OUTPUT\n");
    }
    return 0;
}
