#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[110][110];
int dp[110][110];

int main()
{
    int n;
    while (~scanf("%d", &n)) {
        memset(a, 0, sizeof(a));
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            for (int j = 1 ; j <= n ; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= n ; j++) {
                dp[i][j] = dp[i - 1][j] + a[i][j];
            }
        }
        int mmax = -1e9;
        for (int i = 1 ; i <= n ; i++) {
            for (int j = i ; j <= n ; j++) {
                int sum = 0;
                for (int k = 1 ; k <= n ; k++) {
                    sum += dp[j][k] - dp[i - 1][k];
                    mmax = max(sum, mmax);
                    if (sum < 0)
                        sum = 0;
                }
            }
        }
        printf("%d\n", mmax);
    }
    return 0;
}
