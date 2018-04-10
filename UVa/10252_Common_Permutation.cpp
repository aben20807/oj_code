// 看起來像是 LCS，但是直接排序後比較即可
// 注意空行也算是輸入，所以使用 getline

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
    string s1, s2;
    while (getline(cin, s1)) {
        getline(cin, s2);
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        for (int i = 0, j = 0; i < (int)s1.length() && j < (int)s2.length();) {
            if (s1[i] == s2[j]) {
                printf("%c", s1[i]);
                i++;
                j++;
            } else if (s1[i] < s2[j]) {
                i++;
            } else {
                j++;
            }
        }
        printf("\n");
    }
    return 0;
}
