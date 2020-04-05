#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
typedef long long ll;
using namespace std;

int main()
{
    int t, casecnt = 1;
    scanf("%d\n", &t);
    while (t--) {
        ll n, k;
        scanf("%lld %lld\n", &n, &k);
        printf("Case #%d: ", casecnt++);
        map<ll, ll> q;
        q[n] = 1;
        ll r, l;
        while (k > 0) {
            auto it = prev(q.end());
            ll ttop = it->first;
            ll cnt = it->second;
            q.erase(it);
            r = ttop / 2;
            l = (ttop - 1) / 2;
            q[r] += cnt;
            q[l] += cnt;
            k -= cnt;
        }
        printf("%lld %lld\n", r, l);
    }
    return 0;
}
