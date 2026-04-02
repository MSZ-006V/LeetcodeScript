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
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*>& nodes) {
        // 1. 将 nodes 存入 set，方便 O(1) 查询
        unordered_set<TreeNode*> targetNodes(nodes.begin(), nodes.end());
        return dfs(root, targetNodes);
    }

    TreeNode* dfs(TreeNode* root, unordered_set<TreeNode*>& s) {
        if (!root) return nullptr;

        // 2. 如果当前节点是目标之一，它就是这棵子树潜在的 LCA
        if (s.count(root)) return root;

        // 3. 递归左右子树
        TreeNode* left = dfs(root->left, s);
        TreeNode* right = dfs(root->right, s);

        // 4. 后序逻辑：根据左右子树的返回结果判断
        if (left && right) {
            // 左右都有目标，当前节点就是它们的公共祖先
            return root;
        }
        
        // 否则返回非空的那一个（或者都为空则返回 nullptr）
        return left ? left : right;
    }
};