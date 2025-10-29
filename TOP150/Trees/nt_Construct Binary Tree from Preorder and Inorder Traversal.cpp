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

// tc O(n), sc O(n)
// leetcode105, 106, 利用前序+中序或者后序+中序重建，下面这个方法简单方便快捷
class Solution {
public:
    int preIdx = 0;
    int inIdx = 0;
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int limit){
        if(preIdx >= preorder.size()) return nullptr;
        if(inorder[inIdx] == limit){
            inIdx++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preIdx++]);
        root->left = dfs(preorder, inorder, root->val);
        root->right = dfs(preorder, inorder, limit);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, inorder, INT_MAX);
    }
};
