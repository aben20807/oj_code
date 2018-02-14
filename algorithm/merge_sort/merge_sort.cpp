#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <climits>
using namespace std;

void print_vector(vector<int> a)
{
    vector<int>::iterator iter;
    for (iter = a.begin(); iter != a.end(); iter++) {
        printf("%d ", *iter);
    }
    printf("\n");
}

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
    for (int k = p; k <= r; k++){
        if (L[i] <= R[j]){
            (*A)[k] = L[i];
            i++;
        } else {
            (*A)[k] = R[j];
            j++;
        }
    }
}

void merge_sort(vector<int> *A, int p, int r)
{
    if (p < r){
        int q = (p + r)/ 2;
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        merge(A, p, q, r);
    }
}

int main()
{
    vector<int> a({0, 16, 4, 10, 14, 7, 9, 3, 2, 8, 1});
    print_vector(a);
    merge_sort(&a, 1, a.size() - 1);
    print_vector(a);
    return 0;
}
