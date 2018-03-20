#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> a;

int bs(int t)
{
    int left = 0, right = a.size();
    while (left <= right) {
        int middle = (left + right) / 2;
        if (a[middle] >= t) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    if (a[left] == t)
        return left + 1;
    return -1;
}

int main()
{
    int n, q;
    int casecnt = 1;
    while (scanf("%d%d", &n, &q)) {
        if (n == 0 && q == 0)
            break;
        a.clear();
        for (int i = 0; i < n; i++) {
            int tmp;
            scanf("%d", &tmp);
            a.push_back(tmp);
        }
        sort(a.begin(), a.end());
        printf("CASE# %d:\n", casecnt++);
        for (int i = 0; i < q; i++) {
            int query;
            scanf("%d", &query);
            int result = bs(query);
            if (result == -1) {
                printf("%d not found\n", query);
            } else {
                printf("%d found at %d\n", query, result);
            }
        }
    }
    return 0;
}
