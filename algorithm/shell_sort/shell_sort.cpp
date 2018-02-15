#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
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

int create_A108870(int i)
{
    return (int)ceil((9 * pow((9 / 4.0), i) - 4) / 5.0);
}

template <class T>
void shell_sort(vector<T> *A)
{
    // create gaps
    vector<int> gaps;
    for (int i = 0;; i++) {
        int tmp = create_A108870(i);
        if (tmp >= A->size()) {
            break;
        } else {
            gaps.push_back(tmp);
        }
    }
    reverse(gaps.begin(), gaps.end());
    // print_vector(gaps);
    for (int gap : gaps) {
        for (int i = gap; i <= A->size() - 1; i++) {
            T x = (*A)[i];
            int j = i;
            while (j >= gap && (*A)[j - gap] > x) {
                swap((*A)[j], (*A)[j - gap]);
                j -= gap;
            }
            // print_vector(*A);
        }
    }
}

int main()
{
    vector<int> a({10, 16, 4, 10, 14, 7, 9, 3, 2, 8, 1});
    print_vector(a);
    shell_sort(&a);
    print_vector(a);
    return 0;
}
