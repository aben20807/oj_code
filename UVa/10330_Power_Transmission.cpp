// 因為 node 本身也有流量限制，所以建立 cap 時取邊、左右兩點的最小值
// 因為起點、終點可能有多個，所以各新增一個點當作總起點、終點
// udebug 測資有錯

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int cap[110][110];
int flow[110][110];
int parent[110];
bool vis[110];

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
    int n;
    while (~scanf("%d", &n)) {
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));
        memset(parent, 0, sizeof(parent));
        int node[n + 1];
        for (int i = 1; i <= n; i++) {
            scanf("%d", &node[i]);
        }
        int m;
        scanf("%d", &m);
        while (m--) {
            int a, b, capa;
            scanf("%d%d%d", &a, &b, &capa);
            int realcapa = min(node[a], node[b]);
            realcapa = min(realcapa, capa);
            cap[a][b] = realcapa;
        }
        int sn, dn, tmp;
        scanf("%d%d", &sn, &dn);
        while (sn--) {
            scanf("%d", &tmp);
            cap[0][tmp] = node[tmp];
        }
        while (dn--) {
            scanf("%d", &tmp);
            cap[tmp][n + 1] = node[tmp];
        }
        int ans = ford_fulkerson(0, n + 1, n + 1);
        printf("%d\n", ans);
    }
    return 0;
}
