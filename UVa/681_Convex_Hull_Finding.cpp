// 輸出順序會影響 AC

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef struct Point Point;
struct Point {
    int x;
    int y;
};

double cross(Point o, Point a, Point b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool cmp(Point a, Point b)
{
    if (a.y == b.y)
        return a.x < b.x;
    return a.y < b.y;
}

void ConvexHull(Point *s, int n)
{
    sort(s, s + n, cmp);
    Point ch[n];
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
    printf("%d\n", m);
    for (int i = m - 1; i >= 0; i--) {
        printf("%d %d\n", ch[i].x, ch[i].y);
    }
}

int main()
{
    int t, gg;
    scanf("%d", &t);
    printf("%d\n", t);
    while (t--) {
        int n;
        scanf("%d", &n);
        Point s[n];
        for (int i = 0; i < n; i++)
            scanf("%d%d", &s[i].x, &s[i].y);
        if (t)
            scanf("%d", &gg);
        ConvexHull(s, n);
        if (t)
            printf("-1\n");
    }
    return 0;
}
