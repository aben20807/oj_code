#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int myfind(int x, int p[])
{
    if (x == p[x])
        return x;
    return p[x] = myfind(p[x], p);
}

void myunion(int x, int y, int p[])
{
    int X = myfind(x, p);
    int Y = myfind(y, p);
    p[X] = Y;
}

void printset(int pa[], int n)
{
    for (int i = 0; i <= n; i++) {
        printf("%d ", myfind(i, pa));
    }
    printf("\n");
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        int pa[n + 1] = {0};
        for (int i = 0; i <= n; i++) {
            pa[i] = i;
        }
        while (m--) {
            int command, p, q;
            scanf("%d", &command);
            // printf("%d ", command);
            if (command == 1) {
                scanf("%d%d", &p, &q);
                // printf("%d %d:\n", p, q);
                if (myfind(p, pa) != myfind(q, pa)) {
                    myunion(p, q, pa);
                    // printset(pa, n);
                }
            } else if (command == 2) {
                scanf("%d%d", &p, &q);
                // printf("%d %d:\n", p, q);
                if (myfind(p, pa) != myfind(q, pa)) {
                    if (myfind(p, pa) == pa[p]) {
                        // if move element is root, find a new root for others
                        int newroot;
                        for (int i = 0; i <= n; i++) {
                            if (myfind(i, pa) == myfind(p, pa) && i != p) {
                                newroot = i;
                                break;
                            }
                        }
                        for (int i = 0; i <= n; i++) {
                            if (myfind(i, pa) == myfind(p, pa) && i != p) {
                                pa[i] = newroot;
                            }
                        }
                    }
                    pa[p] = myfind(q, pa);
                    // printset(pa, n);
                }
            } else {
                scanf("%d", &p);
                // printf("%d:\n", p);
                int pset = myfind(p, pa);
                int cnt = 0, sum = 0;
                // printset(pa, n);
                for (int i = 0; i <= n; i++) {
                    if (myfind(i, pa) == pset) {
                        cnt++;
                        sum += i;
                    }
                }
                printf("%d %d\n", cnt, sum);
            }
        }
    }
    return 0;
}
