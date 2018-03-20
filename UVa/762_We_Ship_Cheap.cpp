#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <map>
using namespace std;

map<string, int> vis;
map<string, vector<string>> adj;
map<string, string> fromwho;

void bfs(string c1, string c2)
{
    queue<string> q;
    q.push(c1);
    vis[c1] = 1;
    while (!q.empty()) {
        string cur = q.front();
        q.pop();
        if (cur == c2) {
            return;
        }
        for (int x = 0; x < (int)adj[cur].size(); x++) {
            string nxt = adj[cur][x];
            if (!vis[nxt]) {
                fromwho[nxt] = cur;
                vis[nxt] = 1;
                q.push(nxt);
            }
        }
    }
}

int main()
{
    int n;
    int first = 1;
    while (scanf("%d", &n) != EOF) {
        vis.clear();
        adj.clear();
        fromwho.clear();
        map<string, int> exist;
        while (n--) {
            string c1, c2;
            cin >> c1 >> c2;
            exist[c1] = 1;
            exist[c2] = 1;
            adj[c1].push_back(c2);
            adj[c2].push_back(c1);
        }
        string c1, c2;
        cin >> c1 >> c2;
        bfs(c1, c2);
        if (!first) {
            printf("\n");
        }
        first = 0;
        if (c1 == c2) {
            printf("%s %s\n", c1.c_str(), c2.c_str());
        } else if (fromwho[c2] == "" || !exist[c1] || !exist[c2]) {
            printf("No route\n");
        } else {
            vector<string> ans;
            ans.push_back(c2);
            string last = fromwho[c2];
            while (last != c1) {
                ans.push_back(last);
                last = fromwho[last];
            }
            ans.push_back(c1);
            for (int i = (int)ans.size() - 1; i > 0; i--) {
                printf("%s %s\n", ans[i].c_str(), ans[i - 1].c_str());
            }
        }
    }
    return 0;
}
