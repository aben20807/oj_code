/** 2022/12/22
 * Note: The returned array must be malloced, assume caller calls free().
 * Hard
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

void dfs(int node, int parent, Element** adj_list, int *ans, int *count) {
    // post-order
    Element *cur = adj_list[node];
    while (cur->val != -1) {
        int child = cur->val;
        if (child != parent) {
            dfs(child, node, adj_list, ans, count);
            count[node] += count[child];
            ans[node] += ans[child] + count[child];
        }
        cur = cur->next;
    }
}

void dfs2(int node, int parent, Element** adj_list, int *ans, int *count, int n) {
    // pre-order
    Element *cur = adj_list[node];
    while (cur->val != -1) {
        int child = cur->val;
        if (child != parent) {
            ans[child] = ans[node] - count[child] + n - count[child];
            dfs2(child, node, adj_list, ans, count, n);
        }
        cur = cur->next;
    }
}

int* sumOfDistancesInTree(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    // init adj_list
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

    // init ans
    int *cnt = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) cnt[i] = 1;
    int *ans = (int*)calloc(n, sizeof(int));
    
    // 2 dfs
    dfs(0, -1, adj_list, ans, cnt);
    dfs2(0, -1, adj_list, ans, cnt, n);
    *returnSize = n;
    release_memory(adj_list, n);
    return ans;
}
