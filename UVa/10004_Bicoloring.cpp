#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
using namespace std;

map<int, vector<int>> adj;
map<int, int> vis;
map<int, int> color;

int dfs(int i, int c)
{
    vis[i] = 1;
    color[i] = c;
    for (int x = 0; x < (int)adj[i].size(); x++) {
        int nxt = adj[i][x];
        if (color[i] == color[nxt]) {
            return -1;
        }
        if (!vis[nxt]) {
            return dfs(nxt, !c);
        }
    }
    return 1;
}

int main()
{
    int n;
    while (scanf("%d", &n) && n) {
        int a;
        adj.clear();
        for (int i = 0; i < n; i++) {
            vis[i] = 0;
            color[i] = -1;
        }
        scanf("%d", &a);
        while (a--) {
            int i, j;
            scanf("%d%d", &i, &j);
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
        int result = dfs(0, 0);
        if (result == -1) {
            printf("NOT BICOLORABLE.\n");
        } else {
            printf("BICOLORABLE.\n");
        }
    }
    return 0;
}
