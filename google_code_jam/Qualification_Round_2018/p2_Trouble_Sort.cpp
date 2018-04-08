// TLE in hidden test case

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int v[100001];
int n;

void troublesort()
{
    bool done = false;
    while (!done) {
        done = true;
        for (int i = 0; i < n - 2; i++) {
            if (v[i] > v[i + 2]) {
                done = false;
                swap(v[i], v[i + 2]);
            }
        }
    }
}

int main()
{
    int t;
    int casecnt = 1;
    scanf("%d", &t);
    while (t--) {
        memset(v, -1, sizeof(v));
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
        }
        troublesort();
        bool ok = true;
        int i;
        for (i = 0; i < n - 1; i++) {
            if (v[i] > v[i + 1]) {
                ok = false;
                break;
            }
        }
        printf("Case #%d: ", casecnt++);
        if (ok) {
            printf("OK\n");
        } else {
            printf("%d\n", i);
        }
    }
    return 0;
}
