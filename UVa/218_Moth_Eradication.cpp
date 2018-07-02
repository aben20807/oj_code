#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

typedef struct Point Point;
struct Point {
    double x;
    double y;
};

double cross(Point o, Point a, Point b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool cmp(Point a, Point b)
{
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

double dis(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void ConvexHull(Point *s, int n, Point *ch)
{
    sort(s, s + n, cmp);
    int m = 0;
    for (int i = 0; i < n; i++) {
        while (m >= 2 && cross(ch[m - 2], ch[m - 1], s[i]) >= 0)
            m--;
        ch[m++] = s[i];
    }
    for (int i = n - 1, k = m + 1; i >= 0; i--) {
        while (m >= k && cross(ch[m - 2], ch[m - 1], s[i]) >= 0)
            m--;
        ch[m++] = s[i];
    }
    double length = 0;
    for (int i = 0; i < m; i++) {
        if (i) {
            printf("-");
            length += dis(ch[i], ch[i - 1]);
        }
        printf("(%.1f,%.1f)", ch[i].x, ch[i].y);
    }
    printf("\nPerimeter length = %.2f\n", length);
}

int main()
{
    int n, casecnt = 1;
    while (scanf("%d", &n) && n) {
        Point s[n], t[n];
        for (int i = 0; i < n; i++)
            scanf("%lf%lf", &s[i].x, &s[i].y);
        if (casecnt > 1)
            printf("\n");
        printf("Region #%d:\n", casecnt++);
        ConvexHull(s, n, t);
    }
    return 0;
}
