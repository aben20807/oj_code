#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1e9

struct edge {
    string u;
    string v;
    int cost;
};

int main()
{
    int s, c;
    while (scanf("%d%d", &s, &c)) {
        if (s == 0 && c == 0)
            break;
        vector<string> name;
        map<string, bool> vis;
        map<string, int> dis;
        map<string, string> parent;
        map<string, vector<pair<string, int>>> adj;
        for (int i = 0; i < s; i++) {
            string tmps;
            cin >> tmps;
            vis[tmps] = false;
            dis[tmps] = INF;
            name.push_back(tmps);
        }
        for (int i = 0, cost; i < c; i++) {
            string u, v;
            cin >> u >> v;
            scanf("%d", &cost);
            adj[u].push_back(make_pair(v, cost));
            adj[v].push_back(make_pair(u, cost));
        }
        string start;
        cin >> start;
        dis[start] = 0;
        parent[start] = start;
        /* Prim*/
        for (int i = 0; i < (int)name.size(); i++) {
            int a = -1, mmin = INF;
            for (int j = 0; j < (int)adj[name[i]].size(); j++) {
                string node = adj[name[i]][j].first;
                if (!vis[node] && dis[node] < mmin) {
                    a = j;
                    mmin = dis[node];
                }
            }
            if (a == -1)
                break;
            vis[name[a]] = true;
            for (int j = 0; j < (int)adj[name[i]].size(); j++) {
                string node = adj[name[i]][j].first;
                if (!vis[node] && adj[name[i]][j].second < dis[node]) {
                    dis[node] = adj[name[i]][j].second;
                    parent[node] = name[a];
                }
            }
        }
        for (int i = 0; i < (int)name.size(); i++) {
            printf("%d ", dis[name[i]]);
        }
        printf("\n");
        // if (edgenum == s - 1)
        //     printf("%d\n", len);
        // else
        //     printf("Impossible\n");
    }
    return 0;
}
