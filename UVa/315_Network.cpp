#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <map>
#include <vector>
#include <cstring>
using namespace std;

int low[101];
int dfn[101];
int dfsn;
int ans;
map<int, vector<int>> adj;

void dfs(int pre, int cur)
{
    bool cut = false;
    int child = 0;
    low[cur] = dfn[cur] = ++dfsn;
    for (int x = 0; x < (int)adj[cur].size(); x++) {
        if (!dfn[adj[cur][x]]) {
            dfs(cur, adj[cur][x]);
            low[cur] = min(low[cur], low[adj[cur][x]]);
            if (low[adj[cur][x]] >= dfn[cur])
                cut = true;
            child++;
        } else if (adj[cur][x] != pre) {
            low[cur] = min(low[cur], dfn[adj[cur][x]]);
        }
    }
    if ((child > 1 || pre != -1) && cut)
        ans++;
}

int main()
{
    int n;
    while (scanf("%d", &n) && n) {
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        adj.clear();
        dfsn = 0;
        ans = 0;
        string tmps;
        while (getline(cin, tmps)) {
            if (tmps == "0")
                break;
            stringstream ss(tmps);
            int root, t;
            ss >> root;
            while (ss >> t) {
                adj[root].push_back(t);
                adj[t].push_back(root);
            }
        }
        dfs(-1, 1);
        printf("%d\n", ans);
    }
    return 0;
}
