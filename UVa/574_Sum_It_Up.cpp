#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int t, n;
vector<int> x;
vector<vector<int>> ans;
int ansnum;

void bt(int index, int sum)
{
    if (sum == t) {
        ans.push_back(ans[ansnum]);
        ansnum++;
        return;
    } else {
        for (int i = index; i < n; i++) {
            if (sum + x[i] <= t) {
                sum += x[i];
                ans[ansnum].push_back(x[i]);
                bt(i + 1, sum);
                sum -= x[i];
                ans[ansnum].pop_back();
            }
        }
    }
}

bool cmp(vector<int> a, vector<int> b)
{
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] == b[i])
            continue;
        return a[i] > b[i];
    }
    return a.size() > b.size();
}

void printans(vector<int> a)
{
    printf("%d", a[0]);
    for (int i = 1; i < (int)a.size(); i++) {
        printf("+%d", a[i]);
    }
    printf("\n");
}

int main()
{
    while (scanf("%d%d", &t, &n) && n) {
        x.clear();
        for (auto &a : ans) {
            a.clear();
        }
        ans.resize(1);
        ansnum = 0;
        int tmpn = n;
        while (tmpn--) {
            int tmp;
            scanf("%d", &tmp);
            x.push_back(tmp);
        }
        printf("Sums of %d:\n", t);
        bt(0, 0);
        if (ansnum == 0) {
            printf("NONE\n");
        } else {
            sort(ans.begin(), ans.end() - 1, cmp);
            printans(ans[0]);
            for (int i = 1; i < (int)ans.size(); i++) {
                if (ans[i] == ans[i - 1] || ans[i].size() == 0)
                    continue;
                printans(ans[i]);
            }
        }
    }
    return 0;
}
