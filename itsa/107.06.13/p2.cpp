#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

const int MAX = 1005;
bool sieve[MAX];
vector<int> prime;

void c_p()
{
    for (int i = 2; i < MAX; i++) {
        if (!sieve[i])
            prime.push_back(i);
        for (int j = 0; i * prime[j] < MAX; j++) {
            sieve[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main()
{
    c_p();
    int n;
    while (~scanf("%d", &n)) {
        for (int i = prime.size() - 1; i >= 0; i--) {
            if (prime[i] < n) {
                printf("%d\n", prime[i]);
                break;
            }
        }
    }
    return 0;
}
