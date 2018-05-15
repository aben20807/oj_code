#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define INF 1e9

int w1[50], w2[50];
int dp[310][310];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(w1, 0, sizeof(w1));
        memset(w2, 0, sizeof(w2));
        memset(dp, 0, sizeof(dp));
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%d%d", &w1[i], &w2[i]);
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= m; j++)
                dp[i][j] = INF;
        }
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = w1[i]; j <= m; j++) {
                for (int k = w2[i]; k <= m; k++) {
                    if (dp[j - w1[i]][k - w2[i]] != INF) {
                        dp[j][k] = min(dp[j][k], dp[j - w1[i]][k - w2[i]] + 1);
                    }
                }
            }
        }
        int ans = INF;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= m; j++) {
                if (i * i + j * j == m * m && dp[i][j] != INF) {
                    ans = min(ans, dp[i][j]);
                }
            }
        }
        if (ans != INF)
            printf("%d\n", ans);
        else
            printf("not possible\n");
    }
    return 0;
}
