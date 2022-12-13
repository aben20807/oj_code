/* 2022/12/12
* 解題思路:
*   回去複習高中排列組合，有兩種解法：
*   一、x+2y=n 解出所有解的排列組合
*   二、an=(an-1)+(an-2) 用數列解法 https://youtu.be/px3gFu5FSy4
*   第二種明顯像是 費波那契數列 (Fibonacci Sequence) 可用遞迴
*   然後用 cache 加速
*   這時候利用每個 case 共享 static 變數的 bug 應該可以更快
*/

int climbStairs(int n){
    static int cache[46] = {};
    if (cache[n] != 0) {
        // printf("%d\n", cache[n]);
        return cache[n];
    }
    if (n <= 2) {
        cache[n] = n;
    } else {
        // printf("%d\n", cache[n]);
        cache[n] = climbStairs(n - 1) + climbStairs(n - 2);
        
    }
    return cache[n];
}
