/* 2022/12/24
好難
看到有人推出公式: an = 2*an-1 + an-3
懶得用 recursive + cache，用 for loop
*/

int numTilings(int n){
    long long arr[n+3];
    arr[0] = 1LL;
    arr[1] = 2LL;
    arr[2] = 5LL;
    for (int i = 3; i < n; ++i) {
        arr[i] = (2LL*arr[i-1] + arr[i-3])% (int)(1e9+7);
    }
    return arr[n-1];
}
