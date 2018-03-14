#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    string s1;
    string s2;
    int ans[501] = {0};
    while (cin >> s1) {
        cin >> s2;
        for (int i = 0; i < 501; i++)ans[i] = 0;
        for (int i = s2.size() - 1; i >= 0; i--) {
            for (int j = s1.size() - 1; j >= 0; j--) {
                int tmp = (s1[j] - '0') * (s2[i] - '0');
                // printf("%d\n", tmp);
                ans[(s1.size() - 1 - j) + (s2.size() - 1 - i)] += (tmp);
            }
        }
        for (int i = 0; i < 501; i++) {
            if (ans[i] > 9) {
                ans[i + 1] += ans[i] / 10;
                ans[i] %= 10;
            }
        }
        int i;
        for (i = 500; i >= 1 ; i--) {
            if (ans[i] != 0)
                break;
        }
        for (; i >= 0 ; i--) {
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
