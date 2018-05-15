// 用 Kruskal 生成 MST 並記錄使用的邊長
// 最長的 s 個邊要給衛星使用
// 所求就是去掉這 s 條邊後最長的邊

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point {
    double x;
    double y;
};

struct Edge {
    int a;
    int b;
    double len;
};

int sset[510];

double countdis(struct Point a, struct Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool cmp(struct Edge a, struct Edge b)
{
    return a.len < b.len;
}

int Find(int x)
{
    if (x == sset[x])
        return x;
    return sset[x] = Find(sset[x]);
}

bool Union(struct Edge e)
{
    int x = Find(e.a);
    int y = Find(e.b);
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
        int s, p;
        scanf("%d%d", &s, &p);
        vector<struct Point> point;
        vector<struct Edge> e;
        for (int i = 0; i < p; i++) {
            double x, y;
            scanf("%lf%lf", &x, &y);
            point.push_back({x, y});
        }
        /* connect */
        for (int i = 0; i < p; i++) {
            for (int j = i + 1; j < p; j++) {
                e.push_back({i, j, countdis(point[i], point[j])});
            }
        }
        /* init */
        for (int i = 0; i < p; i++) {
            sset[i] = i;
        }
        /* Kruskal */
        sort(e.begin(), e.end(), cmp);
        vector<double> mstedge;
        for (int i = 0, edgenum = 0; i < (int)e.size(); i++) {
            if (Union(e[i])) {
                mstedge.push_back(e[i].len);
                edgenum++;
            }
            if (edgenum == p - 1)
                break;
        }
        printf("%.2lf\n", mstedge[p - s - 1]);
    }
    return 0;
}
