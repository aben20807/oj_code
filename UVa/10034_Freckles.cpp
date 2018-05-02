#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

struct point {
    double x;
    double y;
} p[110];

struct edge {
    int a;
    int b;
    double len;
} e[110 * 110];

int edgenum;
int sset[110];
double totallen;

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
        totallen += A.len;
        return true;
    }
    return false;
}

int main()
{
    int t;
    while (~scanf("%d", &t)) {
        while (t--) {
            int n, edgenum = 0;
            scanf("%d", &n);
            for (int i = 0; i < n; i++) {
                scanf("%lf%lf", &p[i].x, &p[i].y);
            }
            /* connect all points */
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    double len =
                        sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x) +
                             (p[i].y - p[j].y) * (p[i].y - p[j].y));
                    e[edgenum++] = {i, j, len};
                }
            }
            sort(e, e + edgenum, cmp);
            /* init */
            totallen = 0;
            for (int i = 0; i < n; i++) {
                sset[i] = i;
            }
            /* Kruskal */
            for (int i = 0, edgesum = 0; edgesum != n - 1; i++) {
                if (Union(e[i]))
                    edgesum++;
            }
            printf("%.2lf\n", totallen);
            if (t)
                printf("\n");
        }
    }
    return 0;
}
