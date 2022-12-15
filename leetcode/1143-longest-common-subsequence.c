/* 2022/12/15
* 解題思路: 2D DP 解 LCS
*/
#define max(a,b)             \
({                           \
    __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a > _b ? _a : _b;       \
})

int longestCommonSubsequence(char * text1, char * text2){
    int l1 = strlen(text1);
    int l2 = strlen(text2);
    // printf("%d %d", l1, l2);
    int dp[l1+1][l2+1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i < l1+1; i++) {
        for (int j = 1; j < l2+1; j++) {
            if (text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[l1][l2];
}
