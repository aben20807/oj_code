/** 2022/12/30
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 用 C 寫真的自虐，一堆 pointer
 returnColumnSizes 不用 malloc
 DFS 走到終點就把 path 存起來
 */

typedef struct _graph {
    int** adj;
    int size;
    int* colSize;
} Graph;

typedef struct _path {
    int* list;
    int index;
} Path;

typedef struct _ret {
    int** list;
    int* size_ptr;
    int** colSize_ptr;
} Ret;

void dfs(Graph g, int node, Ret* r_ptr, Path p) {
    // printf("%d ", node);
    p.list[p.index++] = node;
    if (node == g.size - 1) {
        int r_size = ++(*((*r_ptr).size_ptr));

        // printf("%d\n", r_size);
        (*r_ptr).list = (int**)realloc((*r_ptr).list, r_size*sizeof(int*));
        (*r_ptr).list[r_size-1] = (int*)malloc(p.index*sizeof(int));

        if ((*r_ptr).colSize_ptr == NULL) {
            (*r_ptr).colSize_ptr = (int**)malloc(sizeof(int*));
            *((*r_ptr).colSize_ptr) = NULL;
        }
        *((*r_ptr).colSize_ptr) = (int*)realloc(*((*r_ptr).colSize_ptr), r_size*sizeof(int));
        (*((*r_ptr).colSize_ptr))[r_size-1] = p.index;
        // printf("xx %d\n", (*((*r_ptr).colSize_ptr))[r_size-1]);

        for (int i = 0; i < p.index; ++i) {
            (*r_ptr).list[r_size-1][i] = p.list[i];
            // printf("%d ", p.list[i]);
        }
        // printf("\n");
    }
    for (int i = 0; i < g.colSize[node]; ++i) {
        dfs(g, g.adj[node][i], r_ptr, p);
    }
}

int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize, int* returnSize, int** returnColumnSizes){
    bool visit[graphSize];
    int path_list[graphSize];
    Graph g = {graph, graphSize, graphColSize};
    Path p = {path_list, 0};
    
    int** ret_list = NULL;
    *returnSize = 0;
    int** retcol = NULL;
    Ret r = {ret_list, returnSize, retcol};

    dfs(g, 0, &r, p);

    // printf("\n");

    *returnSize = *(r.size_ptr);
    // returnColumnSizes = (int**) malloc(sizeof(int*));
    *returnColumnSizes = (int*) malloc((*returnSize)*sizeof(int));
    for (int i = 0; i < *returnSize; ++i) {
        (*returnColumnSizes)[i] = (*(r.colSize_ptr))[i];
    }

    // for (int i = 0; i < *returnSize; ++i) {
    //     for (int j = 0; j < (*returnColumnSizes)[i]; ++j) {
    //         printf("%d ", r.list[i][j]);
    //     }
    //     printf("\n");
    // }
    return r.list;
}
