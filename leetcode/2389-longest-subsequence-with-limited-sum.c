/** 2022/12/25
注意 subsequence 並不連續，所以 sort 不會影響
sort 後從最小開始拿就會是最長，可再對應回原本的順序所以也還是 subsequence

再來是 prefix sum，基本上就是先統一把前面的加總，
之後就可以讓 queries 查找避免重複運算，
查找時再利用 binary serach 技巧

範例:
nums = [1,7,1,9,1,2]
queries = [3]

sort = [1, 1, 1, 2, 7, 9]
prefix_sum = [1, 2, 3, 5, 12, 21]
upper_bound result = 3 (nums 取 [1,1,1] 得到最長 sebsequence)

 * Note: The returned array must be malloced, assume caller calls free().
 */
 // compare function, compares two elements
int compare (const void * num1, const void * num2) {
    if(*(int*)num1 > *(int*)num2)
        return 1;
    return -1;
}

int upper_bound(int* arr, int N, int X) {
    int mid;
    int low = 0;
    int high = N;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (X >= arr[mid]) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    if(low < N && arr[low] <= X) {
       low++;
    }
    return low;
}

int* answerQueries(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize){
    qsort(nums, numsSize, sizeof(int), compare);
    for (int i = 0; i < numsSize; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    int prefix_sum[numsSize];
    prefix_sum[0] = nums[0];
    for (int i = 1; i < numsSize; ++i) {
        prefix_sum[i] = prefix_sum[i-1] + nums[i];
        printf("%d ", prefix_sum[i]);
    }

    int *ret = (int*)malloc(queriesSize*sizeof(int));
    *returnSize = queriesSize;

    for (int i = 0; i < queriesSize; ++i) {
        ret[i] = upper_bound(prefix_sum, numsSize, queries[i]);
    }
    return ret;
}
