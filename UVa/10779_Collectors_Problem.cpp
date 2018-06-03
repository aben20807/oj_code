#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int cap[45][45];
int flow[45][45];
int parent[45];
bool vis[45];

bool dfs(int cur, int t, int n)
{
    vis[cur] = true;
    if (cur == t)
        return true;
    for (int i = 1; i <= n; i++) {
        if (vis[i])
            continue;
        if (cap[cur][i] - flow[cur][i] > 0 || flow[i][cur] > 0) {
            parent[i] = cur;
            if (dfs(i, t, n))
                return true;
        }
    }
    return false;
}

int find_flow(int s, int t, int n)
{
    int minflow = 1e9;
    for (int i = t; i != s; i = parent[i]) {
        int pre = parent[i];
        if (cap[pre][i] - flow[pre][i] > 0)
            minflow = min(minflow, cap[pre][i] - flow[pre][i]);
        else
            minflow = min(minflow, flow[i][pre]);
    }
    for (int i = t; i != s; i = parent[i]) {
        int pre = parent[i];
        if (cap[pre][i] - flow[pre][i] > 0)
            flow[pre][i] += minflow;
        else
            flow[i][pre] -= minflow;
    }
    return minflow;
}

int ford_fulkerson(int s, int t, int n)
{
    int ret = 0;
    while (1) {
        memset(vis, false, sizeof(vis));
        if (!dfs(s, t, n))
            break;
        ret += find_flow(s, t, n);
    }
    return ret;
}

int main()
{
    int t, casecnt = 1;
    scanf("%d", &t);
    while (t--) {
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));
        memset(parent, 0, sizeof(parent));
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1, k; i <= n; i++) {
            scanf("%d", &k);
            for (int j = 0, ki; j < k; j++) {
                scanf("%d", &ki);
                cap[i][n + ki]++;
            }
        }
        for (int i = 2; i <= n; i++) {
            for (int j = n + 1; j <= n + m; j++) {
                if (cap[i][j] > 0)
                    cap[i][j]--;
                else
                    cap[j][i] = 1;
            }
        }
        for (int i = n + 1; i <= n + m; i++)
            cap[i][n + m + 1] = 1;
        int ans = ford_fulkerson(1, n + m + 1, n + m + 1);
        printf("Case #%d: %d\n", casecnt++, ans);
    }
    return 0;
}
