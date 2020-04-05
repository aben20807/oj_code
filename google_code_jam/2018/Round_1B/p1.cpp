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
            int needp = 0;
            for (int i = 1; i < n; i++){
                if (round((double)i/(double)n) > i/n){
                    needp = i;
                    break;
                }
            }
                // printf("%d\n", needp);
                // printf("%d %d\n", n - respeo, needp - maxp);
                if (n-respeo < needp - maxp) {
                    sum += (gape * (n - respeo));
                } else {
                    for (int i = 1; i <= l; i++) {
                        if ((respeo < n) && (n - respeo >= needp - p[i])) {
                            sum -= (round(100 * (double)p[i] / (double)n));
                            sum += (round(100 * (double)(needp) / (double)n));
                            respeo += (needp - p[i]);
                        }
                    }
                }
            }
            printf("%d\n", (int)sum);
        }
    }
    return 0;
}
