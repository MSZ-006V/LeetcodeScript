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
    // 自底向上，后序遍历
    int dfs(TreeNode* root){
        if(root == nullptr) return 0;

        int l = dfs(root->left);
        int r = dfs(root->right);

        return max(l, r) + 1;
    }
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return dfs(root);
    }
};

class Solution {
public:
    // 自顶向下，先序遍历
    int maxDepth(TreeNode* root) {
        int ans = 0;
        auto dfs = [&](this auto&& dfs, TreeNode* node, int depth) -> void {
            if (node == nullptr) {
                return;
            }
            depth++;
            ans = max(ans, depth);
            dfs(node->left, depth);
            dfs(node->right, depth);
        };
        dfs(root, 0);
        return ans;
    }
};
