#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
using namespace std;

vector<vector<int>> myset;
map<int, int> root;

void myunion(int x, int y)
{
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

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        myset.clear();
        root.clear();
        for (int i = 0; i <= n; i++) {
            root[i] = i;
            vector<int> tmp;
            tmp.push_back(i);
            myset.push_back(tmp);
        }
        while (m--) {
            int command, p, q;
            scanf("%d", &command);
            if (command == 1) {
                scanf("%d%d", &p, &q);
                if (root[p] != root[q]) {
                    myunion(p, q);
                }
            } else if (command == 2) {
                scanf("%d%d", &p, &q);
                if (root[p] != root[q]) {
                    auto iter = myset[root[p]].begin();
                    while (*iter != p) ++iter;
                    myset[root[p]].erase(iter);
                    myset[root[q]].push_back(p);
                    root[p] = root[q];
                }
            } else {
                scanf("%d", &p);
                int cnt = 0, sum = 0;
                for (int i = 0; i < (int)myset[root[p]].size(); i++) {
                    cnt++;
                    sum += myset[root[p]][i];
                }
                printf("%d %d\n", cnt, sum);
            }
        }
    }
    return 0;
}
