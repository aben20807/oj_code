#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
};

int llink[105], rlink[105];
bool used[105];
map<int, vector<int>> edge;

inline double dist(double x1, double x2, double y1, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool dfs(int now)
{
    for (int i = 0; i < (int)edge[now].size(); i++) {
        int nxt = edge[now][i];
        if (!used[nxt]) {
            used[nxt] = true;
            if (rlink[nxt] == -1 || dfs(rlink[nxt])) {
                llink[now] = nxt;
                rlink[nxt] = now;
                return true;
            }
        }
    }
    return false;
}

int bipartite(int nl, int nr)
{
    int ans = 0;
    memset(llink, -1, (nl) * sizeof(int));
    memset(rlink, -1, (nr) * sizeof(int));
    for (int i = 0; i < nl; i++) {
        memset(used, false, (nr) * sizeof(bool));
        if (dfs(i))
            ans++;
    }
    return ans;
}


int main()
{
    int l;
    scanf("%d", &l);
    while (l--) {
        edge.clear();
        int n, m;
        scanf("%d%d", &n, &m);
        Point bob[n], funny[m];
        for (int i = 0; i < n; i++)
            scanf("%d%d", &bob[i].x, &bob[i].y);
        for (int i = 0; i < m; i++)
            scanf("%d%d", &funny[i].x, &funny[i].y);
        for (int i = 0; i < n - 1; i++) {
            double route_gap = dist(bob[i].x, bob[i + 1].x, bob[i].y, bob[i + 1].y);
            for (int j = 0; j < m; j++) {
                double r_f_gap1 = dist(bob[i].x, funny[j].x, bob[i].y, funny[j].y);
                double r_f_gap2 = dist(bob[i + 1].x, funny[j].x, bob[i + 1].y, funny[j].y);
                if (r_f_gap1 + r_f_gap2 <= route_gap * 2)
                    edge[i].push_back(j);
            }
        }
        int ans = bipartite(n, m);
        printf("%d\n", ans + n);
        for (int i = 0; i < n; i++) {
            printf("%s%d %d", (i == 0) ? "" : " ", bob[i].x, bob[i].y);
            if (llink[i] != -1)
                printf(" %d %d", funny[llink[i]].x, funny[llink[i]].y);
        }
        printf("%s\n", (l == 0) ? "" : "\n");
    }
    return 0;
}
