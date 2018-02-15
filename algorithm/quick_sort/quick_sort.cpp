#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

template <class T>
void print_vector(vector<T> a)
{
    typename vector<T>::iterator iter;
    for (iter = a.begin(); iter != a.end(); iter++) {
        printf("%s", (iter == a.begin())? "": " ");
        cout << *iter;
    }
    printf("\n");
}

template <class T>
int partation(vector<T> *A, int p, int r)
{
    int x = (*A)[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++){
        if ((*A)[j] <= x){
            i++;
            swap((*A)[i], (*A)[j]);
        }
    }
    swap((*A)[i+1], (*A)[r]);
    return i + 1;
}

template <class T>
void quick_sort(vector<T> *A, int p, int r)
{
    if (p < r){
        int q = partation(A, p, r);
        quick_sort(A, p, q - 1);
        quick_sort(A, q + 1, r);
    }
}

int main()
{
    vector<int> a({10, 16, 4, 10, 14, 7, 9, 3, 2, 8, 1});
    print_vector(a);
    quick_sort(&a, 0, a.size() - 1);
    print_vector(a);
    return 0;
}
