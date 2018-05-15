// 因為要移動可能會動到 root，一個一個移會 TLE
// 初始化把 root 指向 i+n 就變成一般並查集了

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
using namespace std;

int sset[200020];
int sum[200020];
int num[200020];

int Find(int x)
{
    if (x == sset[x])
        return x;
    return sset[x] = Find(sset[x]);
}

bool Union(int x, int y)
{
    int X = Find(x);
    int Y = Find(y);
    if (X != Y) {
        sset[X] = Y;
        sum[Y] += sum[X];
        num[Y] += num[X];
        return true;
    }
    return false;
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        /* init */
        for (int i = 1; i <= n; i++) {
            sset[i] = i + n;
            sset[i + n] = i + n;
            sum[i + n] = i;
            num[i + n] = 1;
        }
        /* input command */
        while (m--) {
            int command, p, q;
            scanf("%d", &command);
            if (command == 1) {
                scanf("%d%d", &p, &q);
                if (Find(p) != Find(q)) {
                    Union(p, q);
                }
            } else if (command == 2) {
                scanf("%d%d", &p, &q);
                int x = Find(p);
                int y = Find(q);
                if (x != y) {
                    sset[p] = y;
                    sum[x] -= p;
                    sum[y] += p;
                    num[x]--;
                    num[y]++;
                }
            } else {
                scanf("%d", &p);
                int x = Find(p);
                printf("%d %d\n", num[x], sum[x]);
            }
        }
    }
    return 0;
}
