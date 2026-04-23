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
    void dfs(TreeNode* root, int val) {
        if (root == nullptr) return;

        if (val <= root->val) res++;
        val = max(val, root->val);
        dfs(root->left, val);
        dfs(root->right, val);
    }
    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        res = 0;
        dfs(root, INT_MIN);

        return res;       
    }
};