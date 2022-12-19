/** 2022/12/18
 * Note: The returned array must be malloced, assume caller calls free().
 解題思路：
 原本想每個點向後找大於的天數，但是其實會很多重複而且超時
 看討論改使用 stack
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize){
    int *ret = (int*)calloc(temperaturesSize, sizeof(int));
    int stack[temperaturesSize];
    int top = -1;
    
    for (int i = 0; i < temperaturesSize; i++) {
        while(top > -1 && temperatures[stack[top]] < temperatures[i]) {
            ret[stack[top]] = i - stack[top];
            top--;
        }
        stack[++top] = i;
    }
    *returnSize = temperaturesSize;
    return ret;
}
