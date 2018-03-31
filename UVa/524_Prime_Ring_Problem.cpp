// 質數環問題
// 測資不大相鄰最大相加就15+16，所以質數表建到32就好
// 第一個位置是1，所以找後面的即可
// 然後一堆人拿PE是因為題目沒說是空行間隔case，所以最後沒有空行

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;

int n;
int ring[17];
int vis[17];
const int MAX = 32;
vector<int> prime;
bool isComp[MAX]; // 是合數時為true

void create_isComp()
{
    for (int i = 2; i < MAX; i++) {
        if (!isComp[i]) prime.push_back(i);
        for (int j = 0; i * prime[j] < MAX; j++) {
            isComp[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

void bt(int cur)
{
    if (cur == n && !isComp[ring[0] + ring[n - 1]]) { // 判斷最後一個跟1加
        printf("1");
        for (int i = 1; i < n; i++) {
            printf(" %d", ring[i]);
        }
        printf("\n");
    } else {
        for (int i = 2; i <= n; i++) {
            if (!vis[i] && !isComp[i + ring[cur - 1]]) {
                ring[cur] = i;
                vis[i] = 1;
                bt(cur + 1);
                vis[i] = 0;
            }
        }
    }
}

int main()
{
    create_isComp();
    int casecnt = 1;
    while (~scanf("%d", &n)) {
        memset(ring, 0, sizeof(ring));
        memset(vis, 0, sizeof(vis));
        ring[0] = 1;
        if (casecnt > 1) {
            printf("\n");
        }
        printf("Case %d:\n", casecnt++);
        bt(1);
    }
    return 0;
}
