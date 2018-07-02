#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define x first
#define y second
#define EPS 1e-10

pair<double, double> p[4];

int main()
{
    int n;
    scanf("%d", &n);
    while (n--) {
        for (int i = 0; i < 4; i++) {
            scanf("%lf%lf", &p[i].x, &p[i].y);
        }
        double x1 = min(p[2].x, p[3].x);
        double x2 = max(p[2].x, p[3].x);
        double y1 = min(p[2].y, p[3].y);
        double y2 = max(p[2].y, p[3].y);
        if (p[0].x == p[1].x) {
            if (p[0].x < x1 ||
                max(p[0].y, p[1].y) < y1 ||
                p[0].x > x2 ||
                min(p[0].y, p[1].y) > y2) {
                printf("F\n");
            } else {
                printf("T\n");
            }
        } else {
            double k = ((double)(p[0].y - p[1].y)) / (p[0].x - p[1].x);
            double b = ((double)(p[0].y * p[1].x - p[0].x * p[1].y)) / (p[1].x - p[0].x);
            if (k < 0) {
                if (EPS < y1 - (k * x1 + b) || k * x2 + b - y2 > EPS) {
                    printf("F\n");
                } else {
                    if (max(p[0].x, p[1].x) < x1 ||
                        max(p[0].y, p[1].y) < y1 ||
                        min(p[0].x, p[1].x) > x2 ||
                        min(p[0].y, p[1].y) > y2) {
                        printf("F\n");
                    } else {
                        printf("T\n");
                    }
                }
            } else if (k > 0) {
                if (k * x1 + b - y2 > EPS || EPS < y1 - (k * x2 + b)) {
                    printf("F\n");
                } else {
                    if (max(p[0].x, p[1].x) < x1 ||
                        max(p[0].y, p[1].y) < y1 ||
                        min(p[0].x, p[1].x) > x2 ||
                        min(p[0].y, p[1].y) > y2) {
                        printf("F\n");
                    } else {
                        printf("T\n");
                    }
                }
            } else {
                if (max(p[0].x, p[1].x) < x1 ||
                    p[0].y < y1 ||
                    min(p[0].x, p[1].x) > x2 ||
                    p[0].y > y2) {
                    printf("F\n");
                } else {
                    printf("T\n");
                }
            }
        }
    }
    return 0;
}
