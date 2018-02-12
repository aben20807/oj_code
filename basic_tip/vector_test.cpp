#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
    vector<int> a;
    int n = 3;
    while (n--) {
        int tmp;
        scanf("%d", &tmp);
        a.push_back(tmp);
    }
    for (int i = 0; i < a.size(); i++) {
        printf("%d\n", a[i]);
    }
    vector<int>::iterator iter;
    for (iter = a.begin(); iter != a.end(); iter++) {
        printf("%d\n", *iter);
    }
    return 0;
}
