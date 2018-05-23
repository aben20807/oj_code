// 用 902_Password_Search 那樣搜尋會 TLE
// 找到使用 strstr() 的方式，剛好壓底線

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char s[100010];
char query[100010];

int main()
{
    int k;
    scanf("%d", &k);
    while (k--) {
        scanf("%s", s);
        int q;
        scanf("%d", &q);
        while (q--) {
            scanf("%s", query);
            if (strstr( s, query) != NULL) {
                printf("y\n");
            } else {
                printf("n\n");
            }
        }
    }
    return 0;
}
