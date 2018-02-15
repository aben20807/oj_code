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

int main()
{
    vector<double> a({-1, 16, 4, 10, 14, 7, 9, 3, 2, 8, 1});
    print_vector(a);
    return 0;
}
