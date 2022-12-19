/* 2022/12/19
BFS 跟 DFS 似乎都可以
練習一下 BFS 跟在 C 怎麼用 queue
稍微複習 graph 的表達方式: Edge List, Adjacency Matrix, Adjacency Lists
一般都會用後兩種比較方便對應複雜度 Adjacency Matrix: O(V²), Adjacency Lists: O(V+E) 可視情況使用
大多都用 Adjacency Matrix 比較容易，這次試試看 Adjacency Lists
不需要走過所有 node 所以一開始 enqueue source 就好
加個 early_return 一走到目標就跳出
程式頗長不太 easy

一直卡在奇怪的 bug 結果是 memset 用錯

更快解法: 並查集 Disjoint Set Union-find algorithm (DSU)
*/

typedef struct Element {
	int val;
	struct Element* next;
} Element;

void add_edge(Element** adj_list, int u, int v) {
    Element* e = (Element*)malloc(sizeof(Element));
    e->val = v;
    e->next = adj_list[u];
    adj_list[u] = e;
}

void release_memory(Element** adj_list, int n) {
    for (int i = 0; i < n; i++) {
        Element* cur = adj_list[i];
        while (cur) {
            // printf("%d, ", cur->val);
            Element* tmp = cur;
            cur = cur->next;
            free(tmp);
        }
        // printf("\n");
    }
}

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination){
    // init
    Element *adj_list[n];
    for (int i = 0; i < n; i++) {
        adj_list[i] = (Element *)malloc(sizeof(Element));
        adj_list[i]->val = -1;
        adj_list[i]->next = NULL;
    }
    // build Adjacency Lists
    for (int i = 0; i < edgesSize; i++) { // edgesColSize is always 2
        add_edge(adj_list, edges[i][0], edges[i][1]);
        add_edge(adj_list, edges[i][1], edges[i][0]);
    }

    // BFS with queue
	int queue[n];
    int is_visited[n];
    memset(queue, 0, n*sizeof(int));
    memset(is_visited, 0, n*sizeof(int)); // set all nodes to false
    queue[0] = source; // enqueue source
    is_visited[source] = 1;
    int q_head = 0, q_tail = 1;

    while (q_head != q_tail) {
        int pop = queue[q_head++];
        printf("%d:\n", pop); // BFS
        Element* cur = adj_list[pop];
        while (cur->next) {
            // printf("%d %d, ", cur->val, is_visited[cur->val]);
            if (!is_visited[cur->val]) {
                queue[q_tail++] = cur->val;
                is_visited[cur->val] = 1;
                // printf("%d ", cur->val);
                if (cur->val == destination) {
                    goto early_return;
                }
            }
            cur = cur->next;
        }
        // printf("\n");
    }
early_return:;
    bool ret = is_visited[destination];
    release_memory(adj_list, n);
    return ret;
}
