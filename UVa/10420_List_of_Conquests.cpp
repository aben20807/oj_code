#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;

int main()
{
    int n;
    scanf("%d\n", &n);
    map<string, int> m;
    while (n--) {
        char buf[75 + 1];
        fgets(buf, 76, stdin);
        char delim[] = " ";
        char *token = strtok(buf, delim);
        string city(token);
        if ( m.find(city) != m.end() ) {
            m.find(city)->second++;
        } else {
            m[city] = 1;
        }
    }
    for (map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++)
        printf("%s %d\n", iter->first.c_str(), iter->second);
    return 0;
}
