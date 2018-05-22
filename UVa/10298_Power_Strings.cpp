// KMP
// 總長除以最小週期長度即為所求

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

inline void fail (const char *B, int *pi)
{
    int len = strlen(B);
    pi[0] = -1;
    for (int i = 1, cur_pos = -1; i < len; ++i) {
        while (cur_pos != -1 && B[i] != B[cur_pos + 1])
            cur_pos = pi[cur_pos];
        if (B[i] == B[cur_pos + 1]) ++cur_pos;
        pi[i] = cur_pos;
    }
}

int main()
{
    string s;
    while (cin >> s) {
        if (s == ".")
            break;
        int pi[s.length()];
        memset(pi, -1, sizeof(-1));
        fail(s.c_str(), pi);
        int small_period_len = 0;
        if (s.length() % (s.length() - pi[s.length() - 1] - 1) == 0)
            small_period_len = (int)(s.length() - pi[s.length() - 1] - 1);
        else
            small_period_len = (int)(s.length());
        printf("%d\n", (int)s.length() / small_period_len);
    }
    return 0;
}
