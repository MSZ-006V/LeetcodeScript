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
    int res;
    void dfs(TreeNode* node, int p_val, int len) {
        if (node == nullptr) return;

        if (node->val == p_val + 1) {
            len++;
            res = max(res, len);
            dfs(node->left, node->val, len);
            dfs(node->right, node->val, len);
        }
        else {
            dfs(node->left, node->val, 1);
            dfs(node->right, node->val, 1);
        }
    }
    int longestConsecutive(TreeNode* root) {
        if (root == nullptr) return 0;
        res = 0;
        dfs(root, root->val - 1, 0);

        return res;
    }
};