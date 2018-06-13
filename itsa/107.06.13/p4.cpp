#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> adj[50000];
bool vis[50000];
int node[50000];
int l;
bool isfirst = false;

void dfs(int i)
{
    printf("%s%d", (isfirst ? " " : ""), node[i]);
    isfirst = true;
    vis[i] = true;
    for (int j = 0; j < (int)adj[i].size(); j++) {
        int nxt = adj[i][j];
        if (!vis[nxt]) {
            dfs(nxt);
        }
    }
}

int main()
{
    string s;
    while (getline(cin, s)) {
        isfirst = false;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < 50000; i++)
            adj[i].clear();
        stringstream ss(s);
        int x = 0;
        l = (s.length() + 1) / 2;
        int tree[l + 1];
        while (ss >> tree[x++]) {;}
        int lf[l / 3];
        int rf[l / 3];
        for (int i = 0, j = 0; i < l; i += 3, j++) {
            node[j] = tree[i];
            lf[j] = tree[i + 1];
            rf[j] = tree[i + 2];
        }
        for (int i = 0, j = 0; i < l / 3; i++) {
            if (lf[i]) {
                adj[i].push_back(++j);
            }
            if (rf[i]) {
                adj[i].push_back(++j);
            }
        }
        for (int i = 0; i < l / 3; i++) {
            // printf("%d:\n", node[i]);
            for (int j = 0; j < (int)adj[i].size(); j++) {
                // printf("%d ", adj[i][j]);
            }
            // printf("\n");
        }
        dfs(0);
        printf("\n");
    }
    return 0;
}
