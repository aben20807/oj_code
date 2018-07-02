#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define x first
#define y second

void func(double x1, double y1, double x2, double y2, double &k, double &b)
{
    k = (y2 - y1) / (x2 - x1);
    b = y1 - (k * x1);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("INTERSECTING LINES OUTPUT\n");
    while (n--) {
        pair<double, double> p[4];
        for (int i = 0; i < 4; i++) {
            scanf("%lf%lf", &p[i].x, &p[i].y);
        }
        if ((p[0].x != p[1].x) && (p[2].x != p[3].x)) {
            double k1, b1, k2, b2;
            func(p[0].x, p[0].y, p[1].x, p[1].y, k1, b1);
            func(p[2].x, p[2].y, p[3].x, p[3].y, k2, b2);
            if (k1 == k2 && b1 == b2) {
                printf("LINE\n");
            } else if (k1 == k2 && b1 != b2) {
                printf("NONE\n");
            } else {
                double xx, yy;
                xx = (b2 - b1) / (k1 - k2);
                yy = k1 * xx + b1;
                printf("POINT %.2lf %.2lf\n", xx, yy);
            }
        } else {
            if (p[0].x == p[1].x && p[3].x == p[2].x && p[0].x == p[2].x) {
                printf("LINE\n");
            } else if (p[0].x == p[1].x && p[3].x == p[2].x && p[0].x != p[2].x) {
                printf("NONE\n");
            } else {
                double k, b, xx, yy;
                if (p[0].x == p[1].x) {
                    func(p[2].x, p[2].y, p[3].x, p[3].y, k, b);
                    xx = p[0].x;
                    yy = k * xx + b;
                    printf("POINT %.2lf %.2lf\n", xx, yy);
                } else {
                    func(p[0].x, p[0].y, p[1].x, p[1].y, k, b);
                    xx = p[2].x;
                    yy = k * xx + b;
                    printf("POINT %.2lf %.2lf\n", xx, yy);
                }
            }
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}
