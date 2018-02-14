#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
    vector<unsigned long long> a;
    unsigned long long tmp;
    while (scanf("%llu", &tmp) != EOF) {
        if (a.empty()) {
            a.push_back(tmp);
        } else {
            for (int i = 0; i < a.size(); i++) {
                if (tmp > a.at(i)) {
                    vector<unsigned long long>::iterator it = a.begin() + i;
                    a.insert(it, tmp);
                    break;
                }
            }
        }
        if (a.size() % 2 == 1) {
            printf("%llu\n", a.at(a.size() / 2));
        } else {
            printf("%llu\n", (a.at(a.size() / 2 - 1) + a.at(a.size() / 2)) / 2);
        }
    }
    return 0;
}
