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
        printf("%d ", *iter);
    }
    printf("\n");
}

template <class T>
void insertion_sort(vector<T> *A)
{
    for (int i = 2; i < (*A).size(); i++) {
        int key = (*A)[i];
        int j = i - 1;
        while (j > 0 && (*A)[j] > key) {
            (*A)[j + 1] = (*A)[j];
            j--;
        }
        (*A)[j + 1] = key;
    }
}

int main()
{
    vector<int> a({0, 16, 4, 10, 14, 7, 9, 3, 2, 8, 1});
    print_vector(a);
    insertion_sort(&a);
    print_vector(a);
    return 0;
}
