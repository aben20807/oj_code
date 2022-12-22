/* 2022/12/21
重複使用 1971-find-if-path-exists-in-graph.c 的 Adjacency Lists
其他部分都看不太懂@@
跟之前的 bipartite 不太一樣
似乎也可以用 UnionFind 解
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
            printf("%d, ", cur->val);
            Element* tmp = cur;
            cur = cur->next;
            free(tmp);
        }
        printf("\n");
    }
}

 bool dfs(int node, int nodeColor, Element** adj_list, int* color) {
    color[node] = nodeColor;
    printf("%d\n", node);
    Element* cur = adj_list[node];
    while (cur->val != -1) {
        printf("%d\n", cur->val);
        if (color[cur->val] == color[node]) {
            return false;
        }
        if (color[cur->val] == -1) {
            if (!dfs(cur->val, 1 - color[node], adj_list, color)) {
                return false;
            }
        }
        cur = cur->next;
    }
    return true;
}

bool possibleBipartition(int n, int** dislikes, int dislikesSize, int* dislikesColSize){
    // init
    Element *adj_list[n+1];
    int color[n+1]; // 0 stands for red and 1 stands for blue.
    for (int i = 0; i <= n; i++) {
        adj_list[i] = (Element *)malloc(sizeof(Element));
        adj_list[i]->val = -1;
        adj_list[i]->next = NULL;
        color[i] = -1;
    }
    
    // build Adjacency Lists
    for (int i = 0; i < dislikesSize; i++) { // dislikesColSize is always 2
        add_edge(adj_list, dislikes[i][0], dislikes[i][1]);
        add_edge(adj_list, dislikes[i][1], dislikes[i][0]);
    }

    bool ret = true;
    for (int i = 1; i <= n; i++) {
        printf("c %d: %d\n", i, color[i]);
        if (color[i] == -1) {
            // For each pending component, run DFS.
            if (!dfs(i, 0, adj_list, color)) {
                // Return false, if there is conflict in the component.
                ret = false;
                goto early_return;
            }
        }
    }
early_return:;
    release_memory(adj_list, n+1);
    return ret;
}
