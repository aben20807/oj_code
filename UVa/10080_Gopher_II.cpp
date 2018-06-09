// 輸入 n 個 gopher 位置，m 個洞穴位置後
// 把時間內可到的放到 edge 中，本程式使用 adjacency list
// 注意，若 edge 從 0 開始放則 llink, rlink 要初始化成 -1
// 匹配完後，所求死亡數就是 n - 匹配數(存活數)

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

struct Point {
    double x;
    double y;
} gopher[105], hole[105];

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
    int n, m, s, v;
    while (~scanf("%d%d%d%d", &n, &m, &s, &v)) {
        edge.clear();
        for (int i = 0; i < n; i++)
            scanf("%lf%lf", &gopher[i].x, &gopher[i].y);
        for (int i = 0; i < m; i++)
            scanf("%lf%lf", &hole[i].x, &hole[i].y);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                double dis = dist(gopher[i].x, hole[j].x, gopher[i].y, hole[j].y);
                if (dis / v <= s)
                    edge[i].push_back(j);
            }
        }
        int ans = bipartite(n, m);
        printf("%d\n", n - ans);
    }
    return 0;
}
