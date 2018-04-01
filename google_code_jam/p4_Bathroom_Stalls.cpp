#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
typedef long long i64;
using namespace std;

int main()
{
    int t, casecnt = 1;
    scanf("%d", &t);
    while (t--) {
        i64 n, k;
        scanf("%lld%lld", &n, &k);
        printf("Case #%d: ", casecnt++);
        queue<i64> q;
        q.push(n);
        while (k--) {
            i64 ttop = q.front();
            q.pop();
            if (ttop % 2 == 0) {
                i64 r = ttop / 2;
                i64 l = ttop / 2 - 1;
                if (k == 0) {
                    printf("%lld %lld\n", r, l);
                    break;
                }
                if (r > 0)
                    q.push(r);
                if (l > 0)
                    q.push(l);
            } else {
                i64 r = ((ttop - 1) / 2);
                i64 l = r;
                if (k == 0) {
                    printf("%lld %lld\n", r, l);
                    break;
                }
                if (r > 0)
                    q.push(r);
                if (l > 0)
                    q.push(l);
            }
        }
    }
    return 0;
}
