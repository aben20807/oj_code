#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

map<char, int> dfn;
map<char, int> low;
int dfsn;
map<char, bool> in_stk;
map<char, vector<char>> adj;
stack<char> stk;
int ans_cnt;

void dfs(char cur)
{
    char ttop;
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
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    string tmps;
    getline(cin, tmps);
    getline(cin, tmps);
    while (t--) {
        dfsn = 0;
        ans_cnt = 0;
        dfn.clear();
        low.clear();
        adj.clear();
        in_stk.clear();
        while (!stk.empty()) {
            stk.pop();
        }
        vector<char> name;
        char larnode;
        scanf("%c", &larnode);
        getline(cin, tmps);
        for (int i = 0; i <= larnode - 'A'; i++) {
            name.push_back(char('A' + i));
        }
        while (getline(cin, tmps)) {
            if (tmps.length() == 0)
                break;
            char c1 = tmps[0], c2 = tmps[1];
            adj[c1].push_back(c2);
            adj[c2].push_back(c1);
        }
        for (int i = 0; i < (int)name.size(); i++) {
            if (!dfn[name[i]]) {
                dfs(name[i]);
                ans_cnt++;
            }
        }
        printf("%d\n", ans_cnt);
        if (t > 0)
            printf("\n");
    }
    return 0;
}
