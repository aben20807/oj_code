#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
using namespace std;

vector<vector<int>> myset;
map<int, int> root;

int myfind(int x, int p[])
{
    if (x == p[x])
        return x;
    return p[x] = myfind(p[x], p);
}

void myunion(int x, int y)
{
    // int X = myfind(x, p);
    // int Y = myfind(y, p);
    // p[X] = Y;
    int X = root[x];
    int Y = root[y];
    if (myset[X].size() > myset[Y].size()) {
        for (int n : myset[Y]) {
            myset[X].push_back(n);
            root[n] = X;
        }
        myset[Y].clear();
    } else {
        for (int n : myset[X]) {
            myset[Y].push_back(n);
            root[n] = Y;
        }
        myset[X].clear();
    }
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
        myset.clear();
        root.clear();
        int pa[n + 1] = {0};
        for (int i = 0; i <= n; i++) {
            // pa[i] = i;
            root[i] = i;
            vector<int> tmp;
            tmp.push_back(i);
            myset.push_back(tmp);
        }
        while (m--) {
            int command, p, q;
            scanf("%d", &command);
            // printf("%d ", command);
            if (command == 1) {
                scanf("%d%d", &p, &q);
                // printf("%d %d:\n", p, q);
                // if (myfind(p, pa) != myfind(q, pa)) {
                if (root[p] != root[q]) {
                    // myunion(p, q, pa);
                    myunion(p, q);
                    // printset(pa, n);
                }
            } else if (command == 2) {
                scanf("%d%d", &p, &q);
                // printf("%d %d:\n", p, q);
                // if (myfind(p, pa) != myfind(q, pa)) {
                if (root[p] != root[q]) {
                    // if (myfind(p, pa) == pa[p]) {
                    // // if move element is root, find a new root for others
                    // int newroot;
                    // for (int i = 0; i <= n; i++) {
                    // if (myfind(i, pa) == myfind(p, pa) && i != p) {
                    // pa[i] = i;
                    // newroot = i;
                    // break;
                    // }
                    // }
                    // // myunion(p, newroot, pa);
                    // myunion(p, newroot);
                    // // for (int i = 0; i <= n; i++) {
                    // // if (myfind(i, pa) == myfind(p, pa) && i != p) {
                    // // pa[i] = newroot;
                    // // }
                    // // }
                    // }
                    // pa[p] = myfind(q, pa);
                    // printset(pa, n);
                    auto iter = myset[root[p]].begin();
                    while (*iter != p) ++iter;
                    myset[root[p]].erase(iter);
                    myset[root[q]].push_back(p);
                    root[p] = root[q];
                }
            } else {
                scanf("%d", &p);
                // printf("%d:\n", p);
                int pset = myfind(p, pa);
                // printset(pa, n);
                for (int i = 0; i <= n; i++) {
                    if (myfind(i, pa) == pset) {
                        // cnt++;
                        // sum += i;
                    }
                }
                int cnt = 0, sum = 0;
                for (int i = 0; i < (int)myset[root[p]].size(); i++) {
                    cnt++;
                    sum += myset[root[p]][i];
                    // printf("%d", myset[root[p]][i]);
                }
                printf("%d %d\n", cnt, sum);
                // printf("\n");
            }
        }
    }
    return 0;
}
