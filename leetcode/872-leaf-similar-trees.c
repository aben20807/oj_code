/** 2022/12/08
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 * 解題思路:
 *  recursive 把 leaf val 存在一個 array
 *  最多 200 node 所以 leaf 最多 (200+1)/2 = 100 個，array 用 100 就好
 *  可以 traverse 後怎麼一個一個存到 array 是問題
 *  遇到奇怪的 bug，兩個 testcase 會共享 static, global variable 所以不能用
 *  用 point to int 來共享 int，原本寫成錯的 *idx_ptr++ 要注意優先順序
 */

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2){
    int seq1[100] = {};
    int seq2[100] = {};
    int idx1 = 0;
    collect(seq1, &idx1, root1);
    int idx2 = 0;
    collect(seq2, &idx2, root2);
    if (idx1 != idx2) {
        return false;
    }
    for (int i = 0; i < idx1; i++) {
        // printf("%d %d\n", seq1[i], seq2[i]);
        if (seq1[i] != seq2[i]) {
            return false;
        }
    }
    return true;
}

void collect(int *seq, int *idx_ptr, struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        seq[*idx_ptr] = root->val;
        // printf("%d %d\n",*idx_ptr, root->val);
        (*idx_ptr)++;
    } else {
        collect(seq, idx_ptr, root->left);
        collect(seq, idx_ptr, root->right);
    }
}
