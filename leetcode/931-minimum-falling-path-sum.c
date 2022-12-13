/* 2022/12/13
* 解題思路: DP，左上右上可能會超出 index 所以 DP 寬度加2
*/
#define min(a,b)             \
({                           \
    __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a < _b ? _a : _b;       \
})

int INF = 1e9;

int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize){
    int dp[matrixSize+2][matrixSize+2];
    for (int i = 0; i < matrixSize+2; i++) {
        for (int j = 0; j < matrixSize+2; j++)
            dp[i][j] = INF;
    }

    // init first row
    for (int i = 1; i < matrixSize+1; i++) {
        dp[0][i] = matrix[0][i-1];
        // printf("%d, ", dp[0][i]);
    }
    // printf("\n");

    for (int i = 1; i < matrixSize; i++) {
        for (int j = 1; j < matrixSize+1; j++) {
            int t = min(dp[i-1][j-1], dp[i-1][j]);
            dp[i][j] = min(t, dp[i-1][j+1]) + matrix[i][j-1];
            // printf("%d, ", dp[i][j]);
        }
        // printf("\n");
    }

    int ret = INF;
    for (int i = 1; i < matrixSize+1; i++) {
        // printf("%d, ", dp[matrixSize-1][i]);
        ret = min(ret, dp[matrixSize-1][i]);
    }
    return ret;
}
