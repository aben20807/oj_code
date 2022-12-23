/* 2022/12/23
DP with state machine
蠻複雜的，不過 FSM 畫出來就比較明確:
s0 -> s0 (keep cooldown)
    | s2 (buy)
s1 -> s1 (keep buy)
    | s2 (sell)
s2 -> s0 (cooldown after sell)
*/
#define max(a, b) \
({\
    __typeof__ (a) _a = (a);\
    __typeof__ (b) _b = (b);\
    _a > _b ? _a : _b; \
})

int maxProfit(int* prices, int pricesSize){
    int dp[pricesSize][3];
    memset(dp, 0, pricesSize*3*sizeof(int));

    // first day
    dp[0][0] = 0;
    dp[0][1] = -prices[0]; // buy in the first day
    dp[0][2] = 0;

    int min_buy = dp[0][1];
    for (int i = 1; i < pricesSize; ++i) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][2]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        dp[i][2] = dp[i-1][1] + prices[i];
        printf("%d, %d, %d\n", dp[i][0], dp[i][1], dp[i][2]);
    }
    return max(dp[pricesSize-1][0], dp[pricesSize-1][2]);
}
