#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int f[50010];
int g[50010];

int main()
{
    int cas, n;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &f[i]);
        }
        sort(f, f + n);
        long long cnt = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &g[i]);
            for (int j = 0; j < n; ++j) {
                if (f[j] > g[i]) {
                    cnt += n - j;
                    break;
                }
            }
        }
        printf("%lld\n", cnt);
    }

}
