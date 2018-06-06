#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int N = 32010;
int level[N];
int s[N];

int lowbit(int x)
{
    return x & (-x);
}

int get_sum(int index)
{
    int ans = 0;
    while (index > 0) {
        ans += s[index];
        index -= lowbit(index);
    }
    return ans;
}

void change(int index, int delta)
{
    for (int i = index; i <= N; i += lowbit(i))
        s[i] += delta;
}

int main()
{
    int n;
    while (~scanf("%d", &n)) {
        memset(level, 0, sizeof(level));
        memset(s, 0, sizeof(s));
        for (int i = 0, x, y; i < n; i++) {
            scanf("%d%d", &x, &y);
            x++;
            level[get_sum(x)]++;
            change(x, 1);
        }
        for (int i = 0; i < n; i++) {
            printf("%d\n", level[i]);
        }
    }
    return 0;
}
