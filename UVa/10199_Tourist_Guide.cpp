// 找出所有的 Cut Vertex
// 改成使用 string 的 dfs

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<string, int> low;
map<string, int> dfn;
int dfsn;
vector<string> ans;
map<string, vector<string>> adj;

void dfs(string pre, string cur)
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
    if ((child > 1 || pre != "-1") && cut) {
        ans.push_back(cur);
    }
}

int main()
{
    int n, r, casecnt = 1;
    while (scanf("%d", &n) && n) {
        dfn.clear();
        low.clear();
        adj.clear();
        ans.clear();
        dfsn = 0;
        vector<string> name;
        for (int i = 0; i < n; i++) {
            string tmps;
            cin >> tmps;
            name.push_back(tmps);
        }
        scanf("%d", &r);
        for (int i = 0; i < r; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            adj[s1].push_back(s2);
            adj[s2].push_back(s1);
        }
        for (int i = 0; i < n; i++) {
            dfs("-1", name[i]);
        }
        sort(ans.begin(), ans.end());
        if (casecnt > 1)
            printf("\n");
        printf("City map #%d: %d camera(s) found\n", casecnt++, (int)ans.size());
        for (string s : ans) {
            printf("%s\n", s.c_str());
        }
    }
    return 0;
}
