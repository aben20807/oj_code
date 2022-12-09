/** 2022/12/09
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 * 解題思路:
 *  先偷看一下別人大致解法，看到 low, high 關鍵字後回來寫
 *  利用 dfs 記錄路徑中最低及最高
 *  如果 abs 有更大就利用 pointer 更新 ret
 */

void dfs(struct TreeNode* root, int low, int high, int *ret) {
    if (root == NULL) {
        return;
    }
    if (root->val < low) {
        low = root->val;
    } else if (root->val > high) {
        high = root->val;
    }
    // printf("%d %d %d\n", root->val, low, high);
    if (abs(low - high) > *ret) {
        *ret = abs(low - high);
    }
    dfs(root->left, low, high, ret);
    dfs(root->right, low, high, ret);
}

int maxAncestorDiff(struct TreeNode* root){
    int ret = 0;
    dfs(root, root->val, root->val, &ret);
    return ret;
}
