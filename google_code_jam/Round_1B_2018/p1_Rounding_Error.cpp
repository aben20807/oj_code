#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int p[100010];

int main()
{
    int t, casecnt = 1;
    scanf("%d", &t);
    while (t--) {
        int n, l, maxp = 0, respeo = 0;
        scanf("%d%d", &n, &l);
        double sum = 0;
        memset(p, 0, sizeof(p));
        for (int i = 1; i <= l; i++) {
            int tmp;
            scanf("%d", &tmp);
            p[i] = tmp;
            respeo += tmp;
            sum += (round(100 * (double)tmp / (double)n));
            if (maxp < tmp)
                maxp = tmp;
        }
        printf("Case #%d: ", casecnt++);
        if (100 % n == 0) {
            printf("100\n");
        } else {
            double gape = round(100 / (double)n);
            // printf("%lf\n", gape);
            double sum2 = sum;
            if (gape * n > 100) {
                for (int i = 0; i < n - respeo; i++) {
                    sum2 += gape;
                }
            }
            for (int i = 1; i <= l && respeo < n; i++) {
                for (int j = 1; j <= n - respeo; j++) {
                    if (round((double)(j + p[i]) / (double)n) > (j + p[i]) / n) {
                        sum -= (round(100 * (double)p[i] / (double)n));
                        sum += (round(100 * (double)(j + p[i]) / (double)n));
                        respeo += j;
                    }
                }
            }
            sum += (gape * (n - respeo));
            printf("%d\n", (sum > sum2) ? (int)sum : (int)sum2);
        }
    }
    return 0;
}
