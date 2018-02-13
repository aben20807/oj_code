#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

void print_vector(vector<int> a)
{
    vector<int>::iterator iter;
    for (iter = a.begin(); iter != a.end(); iter++) {
        printf("%d ", *iter);
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

void max_heapify(vector<int> *A, int i)
{
    int l = get_left(i);
    int r = get_right(i);
    int largest;
    if (l <= (*A).size() && (*A)[l] > (*A)[i])
        largest = l;
    else
        largest = i;
    if (r <= (*A).size() && (*A)[r] > (*A)[largest])
        largest = r;
    if (largest != i) {
        swap((*A)[i], (*A)[largest]);
        max_heapify(A, largest);
    }
}

void heap_sort(vector<int> *A)
{
    /* Build max heap */
    for (int i = (*A).size() / 2; i >= 1; i--) {
        max_heapify(&(*A), i);
    }
    vector<int> ans;
    for (int i = (*A).size(); i >= 2; i--) {
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
    vector<int> a({0, 16, 4, 10, 14, 7, 9, 3, 2, 8, 1});
    print_vector(a);
    heap_sort(&a);
    print_vector(a);
    return 0;
}
