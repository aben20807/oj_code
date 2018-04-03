#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

int n, t;
int maxsum;
int track[21];
vector<int> tmp;
vector<int> ans;

void bt(int index, int sum)
{
    if (sum > maxsum) {
        maxsum = sum;
        ans = tmp;
    }
    for (int i = index; i < t; i++) {
        if (sum + track[i] <= n) {
            sum += track[i];
            tmp.push_back(track[i]);
            bt(i + 1, sum);
            sum -= track[i];
            tmp.pop_back();
        }
    }
}

int main()
{
    while (~scanf("%d%d", &n, &t)) {
        maxsum = 0;
        memset(track, 0, sizeof(track));
        tmp.clear();
        ans.clear();
        for (int i = 0; i < t; i++) {
            scanf("%d", &track[i]);
        }
        bt(0, 0);
        int anssum = 0;
        for (int i : ans) {
            anssum += i;
            printf("%d ", i);
        }
        printf("sum:%d\n", anssum);
    }
    return 0;
}
