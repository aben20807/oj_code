/**
 * Note: The returned array must be malloced, assume caller calls free().

priority queue (使用 1962-remove-stones-to-minimize-the-total.c + https://www.programiz.com/dsa/priority-queue)
用 C 寫真的考驗耐性
自己刻的 priority queue 太慢 (27 / 39 testcases passed)，還是 C++ STL 厲害
 */

#define DEBUG 0
#define debug(fmt, ...) \
    do { if (DEBUG) fprintf(stdout, fmt, __VA_ARGS__); } while (0)

typedef struct _task {
    int index;
    int enqueueTime;
    int processingTime;
} Task;

int compare(const void * a, const void * b) {
    Task _a = *(Task*) a;
    Task _b = *(Task*) b;
    // debug("%d %d %d\n", _a.enqueueTime, _a.processingTime, _a.index);
    // debug("%d %d %d\n", _b.enqueueTime, _b.processingTime, _b.index);
    if (_a.enqueueTime < _b.enqueueTime)
        return -1;
    return 1;
}

#define LEFT(i) (2 * i + 1)
#define RIGHT(i) (2 * i + 2)

void swap(Task *a, Task *b) {
    Task t = *a;
    *a = *b;
    *b = t;
}

void min_heapify(Task *arr, int arrSize, int i) {
    if (arrSize <= 1) return;
    debug("min_heapify [%d] (%d)\n", arr[i].index, arrSize);
    int l = LEFT(i);
    int r = RIGHT(i);
    int small = i;
    if (l < arrSize && 
        (arr[l].processingTime < arr[small].processingTime || 
        (arr[l].processingTime == arr[small].processingTime && arr[l].index < arr[small].index)))
        small = l;
    if (r < arrSize && 
        (arr[r].processingTime < arr[small].processingTime || 
        (arr[r].processingTime == arr[small].processingTime && arr[r].index < arr[small].index)))
        small = r;
    if (small != i) {
        debug("swap %d %d\n", arr[i].index, arr[small].index);
        swap(&arr[i], &arr[small]);
        min_heapify(arr, arrSize, small);
    }
}

void insert_pq(Task *arr, int* arr_cur_size_ptr, Task newTask) {
    debug("insert %d %d [%d] to %d\n", newTask.enqueueTime, newTask.processingTime, newTask.index, *arr_cur_size_ptr);
    arr[(*arr_cur_size_ptr)++] = newTask;
    for (int i = (*arr_cur_size_ptr)/2 - 1; i >= 0; --i) {
        min_heapify(arr, *arr_cur_size_ptr, i);
    }
}

Task pop_pq(Task *arr, int* arr_cur_size_ptr) {
    Task ret = arr[0];
    debug("pop %d %d [%d] (%d)\n", ret.enqueueTime, ret.processingTime, ret.index, *arr_cur_size_ptr);
    swap(&arr[0], &arr[--(*arr_cur_size_ptr)]);
    for (int i = (*arr_cur_size_ptr)/2 - 1; i >= 0; --i) {
        min_heapify(arr, *arr_cur_size_ptr, i);
    }
    return ret;
}

void print_pq(Task *arr, int arr_cur_size) {
    printf("PQ: ");
    for (int i = 0; i < arr_cur_size; ++i) {
        printf("[%d] ", arr[i].index);
    }
    printf("\n");
}

int* getOrder(int** tasks, int tasksSize, int* tasksColSize, int* returnSize){
    Task t_list[tasksSize];
    for (int i = 0; i < tasksSize; ++i) {
        Task t = {i, tasks[i][0], tasks[i][1]};
        t_list[i] = t;
    }
    // sort
    qsort(t_list, tasksSize, sizeof(Task), compare);
    // print_pq(t_list, tasksSize);

    Task t_next[tasksSize];
    int t_next_size = 0;

    int *ret = (int *)malloc(tasksSize*sizeof(int));
    int ret_index = 0;
    long long curr_time = 0;
    int task_index = 0;
    while (task_index < tasksSize || t_next_size!= 0) {
        debug("\ncurr time: %d\n", curr_time);
        
        if (t_next_size == 0 && curr_time < t_list[task_index].enqueueTime) {
            curr_time = t_list[task_index].enqueueTime;
        }

        while (task_index < tasksSize && curr_time >= t_list[task_index].enqueueTime) {
            insert_pq(t_next, &t_next_size, t_list[task_index]);
            // print_pq(t_next, t_next_size);
            ++task_index;
        }

        Task n = pop_pq(t_next, &t_next_size);
        curr_time += n.processingTime;
        ret[ret_index++] = n.index;
    }

    *returnSize = tasksSize;
    return ret;
}
