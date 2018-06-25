#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct Range Range;
struct Range {
    int pos;
    int start;
    int end;
} r[100010];

int bit[100010];
int ans[100010];
int n;

bool cmp(Range a, Range b)
{
    if (a.end == b.end)
        return a.start < b.start;
    return a.end > b.end;
}

int lowbit(int x)
{
    return x & (-x);
}

int get_sum(int x)
{
    int sum = 0;
    while (x > 0) {
        sum += bit[x];
        x -= lowbit(x);
    }
    return sum;
}

void change(int x, int d)
{
    for (int i = x; i <= n; i += lowbit(i))
        bit[i] += d;
}

int main()
{
    while (~scanf("%d", &n) && n) {
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &r[i].start, &r[i].end);
            r[i].pos = i;
            r[i].start++;
            r[i].end++;
        }
        sort(r, r + n, cmp);
        memset(bit, 0, sizeof(bit));
        ans[r[0].pos] = get_sum(r[0].start);
        change(r[0].start, 1);
        for (int i = 1; i < n; i++) {
            if (r[i].start == r[i - 1].start && r[i].end == r[i - 1].end) {
                ans[r[i].pos] = ans[r[i - 1].pos];
            } else {
                ans[r[i].pos] = get_sum(r[i].start);
            }
            change(r[i].start, 1);
        }
        for (int i = 0; i < n; i++)
            printf("%d%c", ans[i], (i == n - 1) ? '\n' : ' ');
    }
    return 0;
}
