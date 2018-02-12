#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    char buf[20];
    while (fgets(buf, 20, stdin) != 0) {
        buf[strlen(buf) - 1] = '\0';
        string s(buf);
        string ss(s.rbegin(), s.rend());
        printf("%s\n", ss.c_str());
    }
    return 0;
}
