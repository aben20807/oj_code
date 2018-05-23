// 頻寬可能會有多組，所以要加總而不是直接賦值

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int cap[101][101];
int flow[101][101];
int parent[101];
bool vis[101];

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
    int n, casecnt = 1;
    while (scanf("%d", &n) && n) {
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));
        memset(parent, 0, sizeof(parent));
        int s, d, edgenum;
        scanf("%d%d%d", &s, &d, &edgenum);
        while (edgenum--) {
            int a, b, capa;
            scanf("%d%d%d", &a, &b, &capa);
            cap[a][b] += capa;
            cap[b][a] += capa;
        }
        int ans = ford_fulkerson(s, d, n);
        printf("Network %d\n", casecnt++);
        printf("The bandwidth is %d.\n\n", ans);
    }
    return 0;
}
