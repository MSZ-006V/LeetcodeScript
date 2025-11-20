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
    int min_len;
    void dfs(TreeNode* root, int cur_len){
        if(root->left == nullptr && root->right == nullptr) {
            min_len = min(min_len, cur_len);
            return;
        }

        if(root->left) dfs(root->left, cur_len + 1);
        if(root->right) dfs(root->right, cur_len + 1);

    }
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        
        min_len = INT_MAX;
        dfs(root, 1);
        return min_len;
    }
};