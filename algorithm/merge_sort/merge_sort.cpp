#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <climits>
using namespace std;

template <class T>
void print_vector(vector<T> a)
{
    typename vector<T>::iterator iter;
    for (iter = a.begin(); iter != a.end(); iter++) {
        printf("%s", (iter == a.begin()) ? "" : " ");
        cout << *iter;
    }
    printf("\n");
}

template <class T>
void merge(vector<T> *A, int p, int q, int r)
{
    typename vector<T>::const_iterator start = (*A).begin() + p;
    typename vector<T>::const_iterator mid = (*A).begin() + q + 1;
    typename vector<T>::const_iterator end = (*A).begin() + r + 1;
    vector<T> L(start, mid);
    vector<T> R(mid, end);
    int lcnt = 0;
    int rcnt = 0;
    int acnt = p;
    while (lcnt < (int)L.size() && rcnt < (int)R.size()) {
        if (L[lcnt] <= R[rcnt])
            (*A)[acnt++] = L[lcnt++];
        else
            (*A)[acnt++] = R[rcnt++];
    }
    while (lcnt < (int)L.size()) {
        (*A)[acnt++] = L[lcnt++];
    }
    while (rcnt < (int)R.size()) {
        (*A)[acnt++] = R[rcnt++];
    }
}

template <class T>
void merge_sort(vector<T> *A, int p, int r)
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
    vector<int> a({11, 16, 4, 10, 14, 7, 9, 3, 2, 8, 1});
    print_vector(a);
    merge_sort(&a, 0, (int)a.size() - 1);
    print_vector(a);
    return 0;
}
