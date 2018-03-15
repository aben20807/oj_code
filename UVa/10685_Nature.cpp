#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;

string myfind(string x, map<string, string> &p)
{
    if (x == p[x])
        return x;
    else
        return p[x] = myfind(p[x], p);
}

void myunion(string x, string y, map<string, string> &p)
{
    string X = myfind(x, p);
    string Y = myfind(y, p);
    p[X] = Y;
}

int main()
{
    int c, r;
    while (scanf("%d%d", &c, &r)) {
        map<string, string> creatures;
        if (c == 0 && r == 0)
            break;
        for (int i = 0; i < c; i++) {
            string tmp;
            cin >> tmp;
            creatures[tmp] = tmp;
        }
        for (int i = 0; i < r; i++) {
            string c1, c2;
            cin >> c1;
            cin >> c2;
            // printf("%s - %s\n", c1.c_str(), c2.c_str());
            myunion(c1, c2, creatures);
        }
        map<string, int> check;
        for (map<string, string>::iterator iter = creatures.begin();
             iter != creatures.end();
             iter++) {
            string root = myfind(iter->first, creatures);
            check[root]++;
            // printf("%s %s\n", iter->first.c_str(), myfind(iter->first, creatures).c_str());
        }
        int max = 0;
        for (map<string, int>::iterator iter = check.begin();
             iter != check.end();
             iter++) {
            if (max < iter->second) {
                max = iter->second;
            }
        }
        printf("%d\n", max);
    }
    return 0;
}
