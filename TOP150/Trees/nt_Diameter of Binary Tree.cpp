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
    int dfs(TreeNode* root, int& res){
        if(root == nullptr) return 0;

        int left_dia = dfs(root->left, res);
        int right_dia = dfs(root->right, res);

        res = max(res, left_dia + right_dia);

        return 1 + max(left_dia, right_dia);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // tc O(n)
        if(root == nullptr) return 0;
        int res = 0;
        int dia = dfs(root, res);

        return res;
    }
};
