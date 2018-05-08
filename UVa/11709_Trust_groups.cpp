// 找 SCC 個數

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

map<string, int> dfn;
map<string, int> low;
int dfsn;
map<string, bool> in_stk;
map<string, vector<string>> adj;
stack<string> stk;
int scc_cnt;

void dfs(string cur)
{
    string ttop;
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
        scc_cnt++;
    }
}

int main()
{
    int p, t;
    while (scanf("%d%d", &p, &t)) {
        if (p == 0 && t == 0)
            break;
        dfsn = 0;
        scc_cnt = 0;
        dfn.clear();
        low.clear();
        adj.clear();
        while (!stk.empty()) {
            stk.pop();
        }
        string tmps;
        getline(cin, tmps);
        vector<string> name;
        for (int i = 0; i < p; i++) {
            getline(cin, tmps);
            name.push_back(tmps);
        }
        for (int i = 0; i < t; i++) {
            string s1, s2;
            getline(cin, s1);
            getline(cin, s2);
            adj[s1].push_back(s2);
        }
        for (int i = 0; i < p; i++) {
            if (!dfn[name[i]]) {
                dfs(name[i]);
            }
        }
        printf("%d\n", scc_cnt);
    }
    return 0;
}
