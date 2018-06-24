// data(address) 有 2^24-1 種
// accessed 記錄是否有存取過
// 有則去計算與 now 的距離，超過 cache 大小則代表 miss
// 因為 cache 是由小排到大的，所以找到比距離大的後面就都會 hit 所以直接跳出
// 無則一定 miss，每個 cache 的 miss 都加 1
// 抓到 cache 中或是 hit 後把 data 上一個位置 -1, data 當前位置設為 now+1
// 每次 STAT 要把 miss 計算歸零

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = (1 << 24) + 10;
int N;
int bit[MAXN], accessed[MAXN];
int cache[40], miss[40];
int now;

int lowbit(int x)
{
    return x & (-x);
}

int get_sum(int index)
{
    int sum = 0;
    while (index > 0) {
        sum += bit[index];
        index -= lowbit(index);
    }
    return sum;
}

void change(int index, int delta)
{
    for (int i = index; i <= MAXN; i += lowbit(i))
        bit[i] += delta;
}

void access(int num)
{
    if (accessed[num]) {
        int len = get_sum(now) - get_sum(accessed[num] - 1);
        for (int i = 0; i < N; i++) {
            if (cache[i] >= len)
                break;
            miss[i]++;
        }
        change(accessed[num], -1);
    } else {
        for (int i = 0; i < N; i++) {
            miss[i]++;
        }
    }
    accessed[num] = ++now;
    change(accessed[num], 1);
}

int main()
{
    while (~scanf("%d", &N)) {
        memset(bit, 0, sizeof(bit));
        now = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", &cache[i]);
        }
        string cmd;
        while (cin >> cmd) {
            int x, y, b, n;
            switch (cmd[0]) {
            case 'E':
                goto out;
            case 'S':
                for (int i = 0; i < N; i++) {
                    printf("%d%c", miss[i], (i == N - 1) ? '\n' : ' ');
                }
                memset(miss, 0, sizeof(miss));
                break;
            case 'A':
                scanf("%d", &x);
                access(x);
                break;
            case 'R':
                scanf("%d%d%d", &b, &y, &n);
                for (int i = 0; i < n; i++) {
                    access(b + y * i);
                }
                break;
            }
        }
out:
        ;
    }
    return 0;
}
