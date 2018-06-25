#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct Connected Connected;
struct Connected {
    int e;
    int w;
} c[1010 * 1010];

int s[1010];
int m;

bool cmp(Connected a, Connected b)
{
    if (a.e == b.e)
        return a.w < b.w;
    return a.e < b.e;
}

int lowbit(int x)
{
    return x & (-x);
}

long long get_sum(int x)
{
    long long sum = 0;
    while (x > 0) {
        sum += s[x];
        x -= lowbit(x);
    }
    return sum;
}

void change(int x, int d)
{
    for (int i = x; i <= m; i += lowbit(i))
        s[i] += d;
}

int main()
{
    int t, casecnt = 1;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 0; i < k; i++) {
            scanf("%d%d", &c[i].e, &c[i].w);
        }
        sort(c, c + k, cmp);
        memset(s, 0, sizeof(s));
        long long ans = 0;
        for (int i = 0; i < k; i++) {
            ans += i - get_sum(c[i].w);
            change(c[i].w, 1);
        }
        printf("Test case %d: %lld\n", casecnt++, ans);
    }
    return 0;
}
