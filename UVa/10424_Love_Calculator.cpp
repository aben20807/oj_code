#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int get_love(char* s)
{
    int s_sum = 0;
    int l = strlen(s);
    for (int i = 0; i < l; i++) {
        if (isalpha(s[i])) {
            s_sum += (toupper(s[i]) - 'A' + 1);
        }
    }
    if (s_sum >= 100) {
        s_sum = s_sum % 10 + s_sum / 10 % 10 + s_sum / 100;
    }
    while (s_sum >= 10) {
        s_sum = s_sum % 10 + s_sum / 10;
    }
    return s_sum;
}

int main()
{
    char a[25 + 1];
    char b[25 + 1];
    while (fgets(a, 26, stdin) != 0) {
        int a_sum = 0;
        int b_sum = 0;
        a_sum = get_love(a);
        // printf("a %d\n", a_sum);
        if (fgets(b, 26, stdin) != NULL) {
            b_sum = get_love(b);
            // printf("b %d\n", b_sum);
        }
        printf("%.2lf %%\n", (a_sum < b_sum) ?
               100 * (double)a_sum / (double)b_sum :
               100 * (double)b_sum / (double)a_sum);
    }
    return 0;
}
