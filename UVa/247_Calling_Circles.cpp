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
vector<string> scc_ans[30];

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
            scc_ans[scc_cnt].push_back(ttop);
            stk.pop();
            in_stk[ttop] = false;
        } while (ttop != cur);
        scc_cnt++;
    }
}

int main()
{
    int n, m, casecnt = 1;
    while (scanf("%d%d", &n, &m)) {
        if (n == 0 && m == 0)
            break;
        dfsn = 0;
        scc_cnt = 0;
        dfn.clear();
        low.clear();
        adj.clear();
        for (int i = 0; i < 30; i++)
            scc_ans[i].clear();
        while (!stk.empty()) {
            stk.pop();
        }
        vector<string> name;
        map<string, bool> exist;
        for (int i = 0; i < m; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            adj[s1].push_back(s2);
            if (!exist[s1]) {
                exist[s1] = true;
                name.push_back(s1);
            }
            if (!exist[s2]) {
                exist[s2] = true;
                name.push_back(s2);
            }
        }
        for (int i = 0; i < n; i++) {
            if (!dfn[name[i]]) {
                dfs(name[i]);
            }
        }
        if (casecnt > 1)
            printf("\n");
        printf("Calling circles for data set %d:\n", casecnt++);
        for (int i = 0; i < scc_cnt; i++) {
            for (int j = 0; j < (int)scc_ans[i].size() - 1; j++) {
                printf("%s, ", scc_ans[i][j].c_str());
            }
            printf("%s\n", scc_ans[i].back().c_str());
        }
    }
    return 0;
}
