#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

#define PI 2*acos(0.0)

int main()
{
    int t;
    int casecnt = 1;
    scanf("%d", &t);
    while (t--) {
        double a;
        scanf("%lf", &a);
        printf("Case #%d:\n", casecnt++);
        if (a <= 1.414213) {
            double l = 0.0, r = 45.0;
            while (l < r) {
                double i = (l + r) / 2;
                double rad = i * PI / 180.0;
                double tmpa = (sin(rad) + cos(rad));
                if (abs(tmpa - a) < 0.000000000000001) {
                    printf("%.16lf %.16f %.16f\n", sin(rad) / 2, cos(rad) / 2, 0.0);
                    printf("%.16lf %.16f %.16f\n", -1 * cos(rad) / 2, sin(rad) / 2, 0.0);
                    printf("%.16lf %.16f %.16f\n", 0.0, 0.0, 0.5);
                    break;
                }
                if (tmpa < a) {
                    l = i;
                } else {
                    r = i;
                }
            }
        }
    }
    return 0;
}
