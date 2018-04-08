// RE in hidden test case

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int soil[1001][1001];

bool isfill(int i, int j)
{
    return (soil[i - 1][j - 1] &&
            soil[i - 1][j] &&
            soil[i - 1][j + 1] &&
            soil[i][j - 1] &&
            soil[i][j] &&
            soil[i][j + 1] &&
            soil[i + 1][j - 1] &&
            soil[i + 1][j] &&
            soil[i + 1][j + 1]);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(soil, 0, sizeof(soil));
        int a;
        scanf("%d", &a);
        int len = a / 3 + 1;
        int i = 2, j = 2;
        for (int index = 0; index < len - 2; index++, i++) {
            while (!isfill(i, j)) {
                printf("%d %d\n", i, j);
                fflush(stdout);
                int pi, pj;
                scanf("%d%d", &pi, &pj);
                if (pi == 0 && pj == 0) {
                    break;
                }
                soil[pi][pj] = 1;
            }
        }
    }
    return 0;
}
