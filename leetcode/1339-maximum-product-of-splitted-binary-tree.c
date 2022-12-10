/** 2022/12/10
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 * 解題思路:
 *  看 hint 說要 total_sum 所以似乎要跑兩次 dfs
 *  第一次純粹計算 total_sum
 *  第二次利用中間的 sub_sum 計算最大的結果
 */
int calc_total_sum(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return root->val
        + calc_total_sum(root->left)
        + calc_total_sum(root->right);
}

int dfs(struct TreeNode* root, int total_sum, long long *max_prod) {
    if (root == NULL) {
        return 0;
    }
    int sub_sum = root->val
        + dfs(root->left, total_sum, max_prod)
        + dfs(root->right, total_sum, max_prod);
    long long prod = (long long)sub_sum * (long long)(total_sum - sub_sum);
    if (*max_prod < prod) {
        *max_prod = prod;
    }
    return sub_sum;
}

int maxProduct(struct TreeNode* root){
    // calc total sum
    int total_sum = calc_total_sum(root);
    // printf("%d\n", total_sum);
    
    // find max prod
    long long max_prod = 0;
    dfs(root, total_sum, &max_prod);
    return max_prod % (int)(1e9+7);
}
