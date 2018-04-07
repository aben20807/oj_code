// 一般 LCS 問題
// 答案可能有多種，所以 udebug 顯示錯誤不一定 WA 喔

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
    string tmps;
    while (cin >> tmps) {
        vector<string> t1({""}), t2({""});
        t1.push_back(tmps);
        while (cin >> tmps) {
            if (tmps == "#")
                break;
            else
                t1.push_back(tmps);
        }
        while (cin >> tmps) {
            if (tmps == "#")
                break;
            else
                t2.push_back(tmps);
        }
        int dp[102][102];
        int dppath[102][102];
        int n1 = (int)t1.size() - 1;
        int n2 = (int)t2.size() - 1;
        memset(dp, 0, sizeof(dp));
        memset(dppath, 0, sizeof(dppath));
        // printf("%s\n", t1[1].c_str());
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (t1[i] == t2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    dppath[i][j] = 0;
                } else {
                    if (dp[i - 1][j] < dp[i][j - 1]) {
                        dp[i][j] = dp[i][j - 1];
                        dppath[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i - 1][j];
                        dppath[i][j] = 2;
                    }
                }
            }
        }
        int l = dp[n1][n2];
        int i = n1, j = n2;
        vector<string> ans;
        ans.clear();
        while (l > 0) {
            if (dppath[i][j] == 0) {
                ans.push_back(t1[i]);
                l--;
                i--;
                j--;
            } else if (dppath[i][j] == 1) {
                j--;
            } else {
                i--;
            }
        }
        for (int x = ans.size() - 1; x > 0; x--) {
            printf("%s ", ans[x].c_str());
        }
        printf("%s\n", ans[0].c_str());
    }
    return 0;
}
