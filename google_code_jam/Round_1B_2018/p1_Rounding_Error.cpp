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
            for (int i = 1; i <= l && respeo < n; i++) {
                for (int j = 1; j <= n - respeo; j++) {
                    if (round((double)(j + p[i]) / (double)n) > (j + p[i]) / n) {
                        sum -= (round(100.0 * (double)p[i] / (double)n));
                        sum += (round(100.0 * (double)(j + p[i]) / (double)n));
                        respeo += j;
                        break;
                    }
                }
            }
            double gape = round(100.0 / (double)n);
            sum += (gape * (n - respeo));
            printf("%d\n", (int)sum);
        }
    }
    return 0;
}
