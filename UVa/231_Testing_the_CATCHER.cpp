// LDS (LIS)

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int lds(vector<int> &s)
{
    if (s.size() == 0)
        return 0;
    vector<int> v;
    v.push_back(s[s.size() - 1]);
    for (int i = (int)s.size() - 2; i >= 0; i--) {
        int n = s[i];
        if (n >= v.back()) {
            v.push_back(n);
        } else {
            *upper_bound(v.begin(), v.end(), n) = n;
        }
    }
    return v.size();
}

int main()
{
    int tmpn, casecnt = 1;
    while (scanf("%d", &tmpn)) {
        if (tmpn == -1)
            break;
        vector<int> seq;
        seq.push_back(tmpn);
        while (scanf("%d", &tmpn)) {
            if (tmpn == -1)
                break;
            seq.push_back(tmpn);
        }
        if (casecnt > 1)
            printf("\n");
        printf("Test #%d:\n", casecnt++);
        printf("  maximum possible interceptions: %d\n", lds(seq));
    }
    return 0;
}
