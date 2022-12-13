/** 2022/12/11
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 * 解題思路:
 *  看解答(x
 *  Post Order DFS : 先看左邊, 右邊 最後看自己的數值
 *  回傳最大的子樹給上面
 *  中間更新 max_sum
 */
#define max(a,b)             \
({                           \
    __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a > _b ? _a : _b;       \
})

int gain_from_subtree(struct TreeNode* node, int *max_sum) {
    if (!node) {
        return 0;
    }
    int gain_from_left = max(gain_from_subtree(node->left, max_sum), 0);
    int gain_from_right = max(gain_from_subtree(node->right, max_sum), 0);

    *max_sum = max(*max_sum, gain_from_left + gain_from_right + node->val);

    return max(gain_from_left + node->val, gain_from_right + node->val);
}

int maxPathSum(struct TreeNode* root){
    int max_sum = -1.0/0.0; // -INF
    gain_from_subtree(root, &max_sum);
    return max_sum;
}
