#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

int dfn[2002];
int low[2002];
int dfsn;
int ans;
bool in_stk[2002];
map<int, vector<int>> adj;
stack<int> stk;

void dfs(int cur)
{
    int ttop;
    dfn[cur] = low[cur] = ++dfsn;
    stk.push(cur);
    in_stk[cur] = true;
    for (int x = 0; x < (int)adj[cur].size(); x++) {
        if (!dfn[adj[cur][x]]) {
            dfs(adj[cur][x]);
            low[cur] = min(low[cur], low[adj[cur][x]]);
        } else if (in_stk[adj[cur][x]]) {
            low[cur] = min(low[cur], dfn[adj[cur][x]]);
        }
    }
    if (dfn[cur] == low[cur]) {
        do {
            ttop = stk.top();
            stk.pop();
            in_stk[ttop] = false;
        } while (ttop != cur);
        ans++;
        if (ans > 1)
            return;
    }
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m)) {
        if (n == 0 && m == 0)
            break;
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(in_stk, 0, sizeof(in_stk));
        dfsn = 0;
        ans = 0;
        adj.clear();
        while (!stk.empty()) {
            stk.pop();
        }
        for (int i = 0; i < m; i++) {
            int v, w, p;
            scanf("%d%d%d", &v, &w, &p);
            adj[v].push_back(w);
            if (p == 2)
                adj[w].push_back(v);
        }
        dfs(1);
        for (int i = 1; i <= n; i++) {
            if (dfn[i] == 0) {
                ans++;
                if (ans > 1)
                    break;
            }
        }
        if (ans == 1)
            printf("%d\n", ans);
        else
            printf("0\n");
    }
    return 0;
}
