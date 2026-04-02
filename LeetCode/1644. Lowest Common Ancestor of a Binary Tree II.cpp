/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int found = 0;
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        
        // 注意：这里不能直接 return，要先递归
        TreeNode* left = dfs(root->left, p, q);
        TreeNode* right = dfs(root->right, p, q);
        
        // 后序位置：处理当前节点
        if (root == p || root == q) {
            found++;
            return root;
        }
        
        if (left && right) return root; // 当前是 LCA
        return left ? left : right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = dfs(root, p, q);
        return (found == 2) ? res : nullptr; // 只有找齐了才算数
    }
};