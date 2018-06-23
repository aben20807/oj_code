#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int S;
int c[1050][1050];
int a[1050][1050];

int lowbit(int x)
{
    return x & (-x);
}

int get_sum(int x, int y)
{
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        for (int j = y; j > 0; j -= lowbit(j))
            sum += c[i][j];
    return sum;
}

void change(int x, int y, int len)
{
    for (int i = x; i <= S; i += lowbit(i))
        for (int j = y; j <= S; j += lowbit(j))
            c[i][j] += len;
}

int main()
{
    int inst;
    while (~scanf("%d", &inst)) {
        int x, y, len;
        int x1, x2, y1, y2;
        int ans;
        switch (inst) {
        case 0:
            scanf("%d", &S);
            memset(c, 0, sizeof(c));
            memset(a, 0, sizeof(a));
            break;
        case 1:
            scanf("%d%d%d", &x, &y, &len);
            x++;
            y++;
            change(x, y, len);
            break;
        case 2:
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            x1++;
            y1++;
            x2++;
            y2++;
            ans = get_sum(x2, y2) - get_sum(x1 - 1, y2) -
                  get_sum(x2, y1 - 1) + get_sum(x1 - 1, y1 - 1);
            printf("%d\n", ans);
            break;
        case 3:
            goto out;
        }
    }
out:
    return 0;
}
