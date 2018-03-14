#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m)){
        if (n == 0 && m == 0)
            break;
        int p[n];
        for(int i = 0; i < m; i++){
            p[i] = i;
        }
        while (m--){
            int i, j;
            scanf("%d%d", &i, &j);
        }
        printf("ya");
    }
    return 0;
}
