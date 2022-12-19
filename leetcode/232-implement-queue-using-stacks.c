/* 2022/12/16
*/
typedef struct {
    int top_input;
    int top_output;
    unsigned char input[100];
    unsigned char output[100];
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* ret = (MyQueue*)malloc(sizeof(MyQueue));
    ret->top_input = -1;
    ret->top_output = -1;
    memset(ret->input, 0, 100);
    memset(ret->output, 0, 100);
    return ret;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->top_input++;
    obj->input[obj->top_input] = x;
}

int myQueuePop(MyQueue* obj) {
    int ret = myQueuePeek(obj);
    obj->top_output--;
    return ret;
}

int myQueuePeek(MyQueue* obj) {
    // for (int i = obj->top_input; i >= 0; i--) {
    //     printf("i %d, ", obj->input[i]);
    // }
    // for (int i = obj->top_output; i >= 0; i--) {
    //     printf("o %d, ", obj->output[i]);
    // }
    if (obj->top_output == -1) {
        for (int i = obj->top_input; i >= 0; i--) {
            obj->top_output++;
            obj->output[obj->top_output] = obj->input[i];
        }
        obj->top_input = -1;
    }
    return obj->output[obj->top_output];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->top_input == -1 && obj->top_output == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
