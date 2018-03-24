#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

vector<int> prime;
const int MAX = 1010;
bool sieve[MAX];

void create_prime()
{
    for (int i = 2; i < MAX; i++) {
        if (!sieve[i]) prime.push_back(i);
        for (int j = 0; i * prime[j] < MAX; j++) {
            sieve[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

int main()
{
    create_prime();
    int n, c;
    while (~scanf("%d%d", &n, &c)) {
        vector<int> newp = {1};
        for (int i = 0; prime[i] <= n && i < (int)prime.size(); i++) {
            newp.push_back(prime[i]);
        }
        printf("%d %d:", n, c);
        int cnt = newp.size();
        int len;
        if (cnt % 2 == 1) {
            len = 2 * c - 1;
        } else {
            len = 2 * c;
        }
        if (len > cnt) {
            len = cnt;
        }
        for (int i = cnt / 2 - len / 2, j = 0; j < len; j++) {
            printf(" %d", newp[i + j]);
        }
        printf("\n\n");
    }
    return 0;
}
