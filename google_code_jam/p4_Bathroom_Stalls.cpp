#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
typedef long long i64;
using namespace std;

int main()
{
    int t, casecnt = 1;
    scanf("%d\n", &t);
    while (t--) {
        i64 n, k;
        scanf("%lld %lld\n", &n, &k);
        printf("Case #%d: ", casecnt++);
        queue<i64> q;
        q.push(n);
        while (k--) {
            i64 ttop = q.front();
            q.pop();
            i64 r = ttop / 2;
            i64 l = (ttop - 1) / 2;
            if (k == 0) {
                printf("%lld %lld\n", r, l);
                break;
            }
            q.push(r);
            q.push(l);
        }
    }
    return 0;
}
