/* 2022/12/28
Max heap: https://github.com/aben20807/oj_code/blob/65a58779f3a0c62bb6bd008806202cf430815411/algorithm/heap_sort/README.md#L28
上面網址是大學按照書本寫的，從 1 作為 index
下方程式改為可從 0 開始 index
*/

#define LEFT(i) (2 * i + 1)
#define RIGHT(i) (2 * i + 2)

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void max_heapify(int *arr, int arrSize, int i) {
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest = i;
    if (l < arrSize && arr[l] > arr[largest])
        largest = l;
    if (r < arrSize && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        // printf("swap %d %d\n", arr[i], arr[largest]);
        swap(&arr[i], &arr[largest]);
        max_heapify(arr, arrSize, largest);
    }
}

int minStoneSum(int* piles, int pilesSize, int k){
    // build max heap
    int sum = 0;
    for (int i = 0; i < pilesSize; i++) {
        sum += piles[i];
    }
    for (int i = pilesSize/2 - 1; i >= 0; --i) {
        // printf("%d:\n", i);
        max_heapify(piles, pilesSize, i);
    }

    for (int i = 0; i < k; i++) {
        int remove = piles[0] / 2;
        sum -= remove;
        piles[0] -= remove;
        max_heapify(piles, pilesSize, 0);
    }

    // for (int i = 0; i < pilesSize; ++i) {
    //     printf("%d\n", piles[i]);
    // }

    return sum;
}
