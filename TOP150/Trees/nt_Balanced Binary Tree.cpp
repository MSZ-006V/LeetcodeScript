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
    bool status;
    int dfs(TreeNode* root){
        if(root->left == nullptr && root->right == nullptr) return 1;

        int l = 0;
        int r = 0;
        if(root->left) l = dfs(root->left);
        if(root->right) r = dfs(root->right);

        if(abs(l - r) > 1) status = false;

        return max(l, r) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        status = true;

        dfs(root);

        return status;
    }
};
