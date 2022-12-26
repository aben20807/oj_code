/* 2022/12/26
用 greedy 從後面往前看，更新最後一個點
一路更新到 0 就代表成功
*/
bool canJump(int* nums, int numsSize){
    int last_idx = numsSize - 1;
    for (int i = numsSize-1; i >= 0; --i) {
        if (i + nums[i] >= last_idx) {
            last_idx = i;
        }
    }
    return last_idx == 0;
}
