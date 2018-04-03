#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    int t, w, n;
    bool isfirst = true;
    while (~scanf("%d%d%d", &t, &w, &n)) {
        int d[n];
        int v[n];
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &d[i], &v[i]);
        }
        int dp[t + 1];
        bool take[n][t + 1];
        memset(dp, 0, sizeof(dp));
        memset(take, 0, sizeof(take));
        for (int i = 0; i < n; i++) {
            int need = d[i] * 3 * w;//下潛與上浮的時間
            for (int j = t; j >= need; j--) {
                if (dp[j] < dp[j - need] + v[i]) {
                    dp[j] = dp[j - need] + v[i];
                    take[i][j] = true;
                }
            }
        }
        vector<int> ans;
        for (int i = n - 1, j = t; i >= 0; i--) {
            if (take[i][j]) {
                ans.push_back(i);
                j -= d[i] * 3 * w;
            }
        }
        if (!isfirst) {
            printf("\n");
        } else {
            isfirst = false;
        }
        printf("%d\n%d\n", dp[t], (int)ans.size());
        auto it = ans.rbegin();
        while (it != ans.rend()) {
            printf("%d %d\n", d[*it], v[*it]);
            it++;
        }
    }
    return 0;
}
