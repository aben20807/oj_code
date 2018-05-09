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
    int n;
    scanf("%d", &n);
    while (n--) {
        string s;
        cin >> s;
        int pi[s.length()];
        memset(pi, -1, sizeof(-1));
        fail(s.c_str(), pi);
        if (s.length() % (s.length() - pi[s.length() - 1] - 1) == 0)
            printf("%d\n", (int)(s.length() - pi[s.length() - 1] - 1));
        else
            printf("%d\n", (int)s.length());
        if (n > 0)
            printf("\n");
    }
    return 0;
}
