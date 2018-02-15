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

int get_left(int i)
{
    return 2 * i;
}

int get_right(int i)
{
    return 2 * i + 1;
}

template <class T>
void max_heapify(vector<T> *A, int i)
{
    int l = get_left(i);
    int r = get_right(i);
    int largest;
    if (l <= (*A).size() - 1 && (*A)[l] > (*A)[i])
        largest = l;
    else
        largest = i;
    if (r <= (*A).size() - 1 && (*A)[r] > (*A)[largest])
        largest = r;
    if (largest != i) {
        swap((*A)[i], (*A)[largest]);
        max_heapify(A, largest);
    }
}

template <class T>
void heap_sort(vector<T> *A)
{
    /* Build max heap */
    for (int i = (*A).size() - 1 / 2; i >= 1; i--) {
        max_heapify(&(*A), i);
    }
    vector<int> ans(0);
    for (int i = (*A).size() - 1; i >= 2; i--) {
        int t = (*A)[1];
        swap((*A)[1], (*A)[i]);
        (*A).pop_back();
        ans.push_back(t);
        max_heapify(&(*A), 1);
    }
    ans.push_back((*A)[1]);
    (*A) = ans;
}

int main()
{
    vector<int> a({-1, 16, 4, 10, 14, 7, 9, 3, 2, 8, 1});
    print_vector(a);
    heap_sort(&a);
    print_vector(a);
    return 0;
}
