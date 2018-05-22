// reverse 後去找 match

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

inline void fail (string B, int *pi)
{
    int len = B.length();
    pi[0] = -1;
    for (int i = 1, cur_pos = -1; i < len; ++i) {
        while (cur_pos != -1 && B[i] != B[cur_pos + 1])
            cur_pos = pi[cur_pos];
        if (B[i] == B[cur_pos + 1])
            ++cur_pos;
        pi[i] = cur_pos;
    }
}

inline int match(string A, string B, int *pi)
{
    int lenA = A.length();
    int cur_pos = -1;
    for (int i = 0; i < lenA; ++i) {
        while (cur_pos != -1 && A[i] != B[cur_pos + 1])
            cur_pos = pi[cur_pos];
        if (A[i] == B[cur_pos + 1])
            ++cur_pos;
    }
    return cur_pos;
}

int main()
{
    string s;
    while (cin >> s) {
        string s_rev(s.rbegin(), s.rend());
        int pi_rev[s.length()];
        memset(pi_rev, -1, sizeof(-1));
        fail(s_rev, pi_rev);

        int pos = match(s, s_rev, pi_rev);
        // printf("%d\n", pos);
        printf("%s", s.c_str());
        for (int i = pos + 1; i <= (int)s.length() - 1; i++)
            printf("%c", s_rev[i]);
        printf("\n");
    }
    return 0;
}
