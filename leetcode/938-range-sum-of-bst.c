/** 2022/12/07
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * 解題思路:
 *  recursive
 *  目前 node 的 val 有在範圍內就加上自己的還有左右
 *  否則就返回左右的相加
 *  面試可能考如果不用 recursive 怎麼解
 * };
 */
int rangeSumBST(struct TreeNode* root, int low, int high){
    if (root == NULL) {
        return 0;
    }
    if (root->val >= low && root->val <= high) {
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    } else {
        return rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
}
