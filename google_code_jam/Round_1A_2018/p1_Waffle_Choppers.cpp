// hidden test not accept

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int r, c, h, v;
char wa[101][101];

int countch(int i, int ii, int j, int jj)
{
    int sum = 0;
    for (int x = i; x < ii; x++) {
        for (int y = j; y < jj; y++) {
            if (wa[x][y] == '@')
                sum++;
        }
    }
    return sum;
}

int main()
{
    int t, casecnt = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d%d", &r, &c, &h, &v);
        memset(wa, 0, sizeof(wa));
        int chcount = 0;
        for (int i = 0; i < r; i++) {
            scanf("%s", wa[i]);
            for (int j = 0; j < c; j++) {
                if (wa[i][j] == '@')
                    chcount++;
            }
        }
        printf("Case #%d: ", casecnt++);
        if (chcount % ((h + 1) * (v + 1)) != 0) {
            printf("IMPOSSIBLE\n");
        } else {
            bool isp = false;
            int each = chcount / ((h + 1) * (v + 1));
            for (int i = 1; i < r; i++) {
                for (int j = 1; j < c; j++) {
                    if (countch(0, i, 0, j) == each &&
                        countch(i, r, 0, j) == each &&
                        countch(0, i, j, c) == each &&
                        countch(i, r, j, c) == each) {
                        isp = true;
                        goto out;
                    }
                }
            }
out:
            if (isp) {
                printf("POSSIBLE\n");
            } else {
                printf("IMPOSSIBLE\n");
            }
        }
    }
    return 0;
}
