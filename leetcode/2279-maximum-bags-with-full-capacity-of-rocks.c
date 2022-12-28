/* 2022/12/27
把剩下的容量由小到大排序一下
從小開始填滿
注意最後一個是否有滿
*/
int compare (const void * num1, const void * num2) {
    if(*(int*)num1 > *(int*)num2)
        return 1;
    return -1;
}

int maximumBags(int* capacity, int capacitySize, int* rocks, int rocksSize, int additionalRocks){
    int remain[capacitySize];
    for (int i = 0; i < capacitySize; ++i) {
        remain[i] = capacity[i] - rocks[i];
    }
    qsort(remain, capacitySize, sizeof(int), compare);
    for (int i = 0; i < capacitySize; ++i) {
        printf("%d ", remain[i]);
    }
    int i;
    bool last_full = true;
    for (i = 0; i < capacitySize && additionalRocks >= 0; ++i) {
        if (additionalRocks < remain[i]) {
            last_full = false;
        }
        additionalRocks -= remain[i];
    }
    return i - (last_full ? 0 : 1);
}
