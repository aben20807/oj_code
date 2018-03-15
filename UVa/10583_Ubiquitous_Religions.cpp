#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int myfind(int x, int* p)
{
    if (x == p[x])
        return x;
    else
        return p[x] = myfind(p[x], p);
}

void myunion(int x, int y, int* p)
{
    int X = myfind(x, p);
    int Y = myfind(y, p);
    p[X] = Y;
}

int main()
{
    int n, m, case_cnt = 1;
    while (scanf("%d%d", &n, &m)) {
        if (n == 0 && m == 0)
            break;
        int p[n];
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        while (m--) {
            int i, j;
            scanf("%d%d", &i, &j);
            myunion(i, j, p);
        }
        int count = 0;
        int check[n] = {0};
        for (int i = 0; i < n; i++) {
            // printf("%d: %d\n", i, myfind(i, p));
            int root = myfind(i, p);
            check[root]++;
            if (check[root] == 1) {
                count++;
            }
        }
        printf("Case %d: %d\n", case_cnt++, count);
    }
    return 0;
}
