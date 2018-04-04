#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int dp[10201];

int main()
{
    int m, n;
    while (~scanf("%d%d", &m, &n)) {
        int p[n];
        int f[n];
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &p[i], &f[i]);
        }
        m += (m > 1800) ? 200 : 0;
        for (int i = 1; i <= m; i++) {
            dp[i] = -1e9;
        }
        for (int i = 0; i < n; i++) {
            for (int j = m; j >= p[i]; j--) {
                if (dp[j] < dp[j - p[i]] + f[i]) {
                    dp[j] = dp[j - p[i]] + f[i];
                }
            }
        }
        int pay = m;
        if (pay > 2000 && pay <= 2200) {
            pay -= 200;
        }
        int mmax = -1, ans = 0;
        for (int i = pay; i >= 0; i--) {
            if (dp[i] > mmax) {
                mmax = dp[i];
                ans = i;
            }
        }
        for (int i = m; i > 2000; i--) {
            if (dp[i] > mmax) {
                mmax = dp[i];
                ans = i;
            }
        }
        printf("%d\n", dp[ans]);
    }
    return 0;
}
