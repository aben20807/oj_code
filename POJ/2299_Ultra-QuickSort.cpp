#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <climits>
using namespace std;

long long op;

void merge(vector<int> *A, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    vector<int> L(n1 + 2);
    vector<int> R(n2 + 2);
    for (int i = 1; i <= n1; i++)
        L[i] = (*A)[p + i - 1];
    for (int i = 1; i <= n2; i++)
        R[i] = (*A)[q + i];
    L[n1 + 1] = INT_MAX;
    R[n2 + 1] = INT_MAX;
    int i = 1;
    int j = 1;
    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            (*A)[k] = L[i++];
        } else {
            (*A)[k] = R[j++];
            op += (n1 - i + 1);
        }
    }
}

void merge_sort(vector<int> *A, int p, int r)
{
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main()
{
    int n;
    while (scanf("%d", &n) && n) {
        op = 0;
        vector<int> a(1);
        for (int i = 1; i <= n; i++) {
            int tmp;
            scanf("%d", &tmp);
            a.push_back(tmp);
        }
        merge_sort(&a, 1, a.size() - 1);
        printf("%lld\n", op);
    }
    return 0;
}
