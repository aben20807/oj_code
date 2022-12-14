/* 2022/12/14
* 解題思路: 1D DP
*/
#define max(a,b)             \
({                           \
    __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a > _b ? _a : _b;       \
})

int rob(int* nums, int numsSize){
    int dp[numsSize+1];
    dp[0] = 0;
    dp[1] = nums[0];
    for (int i = 2; i < numsSize+1; i++) {
        dp[i] = max(dp[i-2]+nums[i-1], dp[i-1]);
    }
    return dp[numsSize];
}
