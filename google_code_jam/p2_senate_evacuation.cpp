#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int p[26];
double v[26];
int n;
int sum;

bool can_take(int x, int y)
{
    if (sum - 2 < 0 || p[x] - 1 < 0 || p[y] - 1 < 0) {
        return false;
    }
    if (x == y && p[x] - 2 < 0) {
        return false;
    }
    int tmp[26];
    double tmpv[26];
    for (int i = 0; i < n; i++) {
        tmp[i] = p[i];
        if (i == x || i == y) {
            tmp[i]--;
            if (x == y) {
                tmp[i]--;
            }
        }
        tmpv[i] = (double)tmp[i] / (sum - 2);
        if (tmpv[i] > 0.5) {
            return false;
        }
    }
    for (int i = 0; i < n; i++) {
        p[i] = tmp[i];
        v[i] = tmpv[i];
    }
    sum -= 2;
    return true;
}

int main()
{
    int t, casecnt = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        memset(p, 0, sizeof(p));
        sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
            sum += p[i];
        }
        for (int i = 0; i < n; i++) {
            v[i] = (double)p[i] / sum;
        }
        printf("Case #%d:", casecnt++);
        while (sum > 0 && sum != 3) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (can_take(i, j)) {
                        printf(" %c%c", 'A' + i, 'A' + j);
                    }
                }
            }
        }
        if (sum == 3) {
            int i;
            for (i = 0; i < n; i++) {
                if (p[i] > 0) {
                    printf(" %c", 'A' + i);
                    p[i]--;
                    sum--;
                    break;
                }
            }
            for (; i < n; i++) {
                if (p[i] > 0) {
                    printf(" %c", 'A' + i);
                    p[i]--;
                    sum--;
                    break;
                }
            }
            for (; i < n; i++) {
                if (p[i] > 0) {
                    printf("%c", 'A' + i);
                    p[i]--;
                    sum--;
                    break;
                }
            }
        }
        printf("\n");
    }
}
