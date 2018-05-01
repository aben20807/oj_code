#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9
#define B first
#define W second

int dis[20010];
bool inq[20010];
int cnt[20010];

int main()
{
    int t, casecnt = 1;
    while (~scanf("%d", &t)) {
        while (t--) {
            int n, m, S, T;
            map<int, vector<pair<int, int>>> adj;
            scanf("%d%d%d%d", &n, &m, &S, &T);
            for (int i = 0; i < m; i++) {
                int a, b, w;
                scanf("%d%d%d", &a, &b, &w);
                adj[a].push_back(make_pair(b, w));
                adj[b].push_back(make_pair(a, w));
            }
            /* init */
            for (int i = 0; i < n; i++) {
                dis[i] = INF;
                inq[i] = false;
                cnt[i] = 0;
            }
            /* SPFA */
            dis[S] = 0;
            inq[S] = true;
            queue<int> q;
            q.push(S);
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                inq[cur] = false;
                for (int x = 0; x < (int)adj[cur].size(); x++) {
                    int v = adj[cur][x].B;
                    int w = adj[cur][x].W;
                    if (dis[cur] + w < dis[v]) {
                        dis[v] = dis[cur] + w;
                        if (!inq[v]) {
                            q.push(v);
                            inq[v] = true;
                            cnt[v]++;
                            if (cnt[v] >= n)
                                goto out;
                        }
                    }
                }
            }
out:
            printf("Case #%d: ", casecnt++);
            if (dis[T] == INF)
                printf("unreachable\n");
            else
                printf("%d\n", dis[T]);
        }
    }
    return 0;
}
