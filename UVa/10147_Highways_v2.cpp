// 先算好 n 個點彼此距離存到 w[][]
// 把已經連好的 m 條路徑的 w 設成 0
// 若 Union 的邊大於 0 代表是新增的所以印出
// 若新增總長度為 0 代表沒有新增就印出指定字串

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

struct point {
    double x;
    double y;
};

struct edge {
    int a;
    int b;
    double len;
};

int edgenum;
int sset[800];
double w[800][800];

bool cmp(edge A, edge B)
{
    return A.len < B.len;
}

int Find_Root(int x)
{
    if (x == sset[x])
        return x;
    return sset[x] = Find_Root(sset[x]);
}
bool Union(edge A)
{
    int x = Find_Root(A.a);
    int y = Find_Root(A.b);
    if (x != y) {
        sset[x] = y;
        return true;
    }
    return false;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        vector<struct point> p;
        p.push_back({0, 0});
        vector<struct edge> e;
        e.push_back({0, 0, 0});
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            double x, y;
            scanf("%lf%lf", &x, &y);
            p.push_back({x, y});
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                w[i][j] =
                    sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x) +
                         (p[i].y - p[j].y) * (p[i].y - p[j].y));
            }
        }
        /* init */
        for (int i = 0; i <= n; i++) {
            sset[i] = i;
        }
        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            w[x][y] = 0;
            w[y][x] = 0;
        }
        /* connect all points */
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                e.push_back({i, j, w[i][j]});
            }
        }
        /* Kruskal */
        sort(e.begin(), e.end(), cmp);
        double ans = 0;
        for (int i = 0; i < (int)e.size(); i++) {
            if (Union(e[i])) {
                ans += e[i].len;
                if (e[i].len > 0)
                    printf("%d %d\n", e[i].a, e[i].b);
            }
        }
        if (ans == 0.0)
            printf("No new highways need\n");
        if (t)
            printf("\n");
    }
    return 0;
}
