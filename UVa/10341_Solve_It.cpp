#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

double p, q, r, s, t, u;

double f(double x)
{
    return p * exp(-1 * x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main()
{
    while (~scanf("%lf%lf%lf%lf%lf%lf", &p, &q, &r, &s, &t, &u)) {
        double l = 0, r = 1, mid = (l + r) / 2;
        double result;
        bool has_ans = false;
        while (l < r) {
            mid = (l + r) / 2;
            result = f(mid);
            if (abs(result) < 0.0000001) {
                has_ans = true;
                break;
            } else if (result > 0) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (has_ans)
            printf("%.4lf\n", mid);
        else
            printf("No solution\n");
    }
    return 0;
}
