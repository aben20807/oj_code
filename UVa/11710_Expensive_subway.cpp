// 這題建議用 Prim，但還是可以用 Kruskal
// 起點好像不管哪個演算法都不太重要
// 主要是看可否產生 MST，可則輸出長度

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
    string u;
    string v;
    int cost;
};

map<string, string> sset;

bool cmp(struct edge a, struct edge b)
{
    return a.cost < b.cost;
}

string Find(string x)
{
    if (x == sset[x]) {
        return x;
    }
    return sset[x] = Find(sset[x]);
}

bool Union(struct edge e)
{
    string x = Find(e.u);
    string y = Find(e.v);
    if (x != y) {
        sset[x] = y;
        return true;
    }
    return false;
}

int main()
{
    int s, c;
    while (scanf("%d%d", &s, &c)) {
        if (s == 0 && c == 0)
            break;
        sset.clear();
        for (int i = 0; i < s; i++) {
            string tmps;
            cin >> tmps;
            sset[tmps] = tmps;
        }
        vector<struct edge> e;
        for (int i = 0, cost; i < c; i++) {
            string u, v;
            cin >> u >> v;
            scanf("%d", &cost);
            e.push_back({u, v, cost});
        }
        string start;
        cin >> start;
        /* Kruskal */
        sort(e.begin(), e.end(), cmp);
        int len = 0, edgenum = 0;
        for (int i = 0; i < (int)e.size(); i++) {
            if (Union(e[i])) {
                len += e[i].cost;
                edgenum++;
            }
            if (edgenum == s - 1)
                break;
        }
        if (edgenum == s - 1)
            printf("%d\n", len);
        else
            printf("Impossible\n");
    }
    return 0;
}
