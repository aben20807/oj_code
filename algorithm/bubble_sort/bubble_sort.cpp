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

void bubble_sort(vector<int> *A)
{
    for (int i = 0; i <= A->size() - 1; i++){
        for (int j = 0; j < A->size()-i-1; j++){
            if ((*A)[j] > (*A)[j+1]){
                swap((*A)[j], (*A)[j+1]);
            }
        }
    }
}

int main()
{
    vector<int> a({0, 16, 4, 10, 14, 7, 9, 3, 2, 8, 1});
    print_vector(a);
    bubble_sort(&a);
    print_vector(a);
    return 0;
}
