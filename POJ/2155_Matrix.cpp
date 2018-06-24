#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 1010;
int bit[MAXN][MAXN];
int N;

int lowbit(int x)
{
    return x & (-x);
}

int get_sum(int x, int y)
{
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        for (int j = y; j > 0; j -= lowbit(j))
            sum += bit[i][j];
    return sum;
}

void change(int x, int y, int val)
{
    for (int i = x; i <= MAXN; i += lowbit(i))
        for (int j = y; j <= MAXN; j += lowbit(j))
            bit[i][j] += val;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int T;
        scanf("%d%d ", &N, &T);
        memset(bit, 0, sizeof(bit));
        while (T--) {
            char cmd;
            scanf("%c", &cmd);
            int x, y, x1, y1, x2, y2, ans;
            switch (cmd) {
            case 'C':
                scanf("%d%d%d%d ", &x1, &y1, &x2, &y2);
                change(x1, y1, 1);
                change(x2 + 1, y1, -1);
                change(x1, y2 + 1, -1);
                change(x2 + 1, y2 + 1, 1);
                break;
            case 'Q':
                scanf("%d%d ", &x, &y);
                ans = get_sum(x, y);
                printf("%d\n", ans % 2);
                break;
            }
        }
        if (t)
            printf("\n");
    }
    return 0;
}
