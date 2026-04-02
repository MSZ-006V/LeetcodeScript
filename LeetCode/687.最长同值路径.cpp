/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 思路可以参考leetcode 543，二叉树的直径，求最长路径，路径上的节点值相同
    int res;
    int dfs(TreeNode* node){
        if (node == nullptr) {
            return -1; // 下面 +1 后，对于叶子节点就刚好是 0
        }

        int l_len = dfs(node->left) + 1; // 左子树最大链长+1
        int r_len = dfs(node->right) + 1; // 右子树最大链长+1

        if (node->left && node->left->val != node->val) l_len = 0; // 链长视作 0
        if (node->right && node->right->val != node->val) r_len = 0; // 链长视作 0
        res = max(res, l_len + r_len); // 两条链拼成路径

        return max(l_len, r_len); // 当前子树最大链长
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root == nullptr) return 0;
        res = 0;

        int cur = dfs(root);

        return res;
    }
};