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
    TreeNode* invertTree(TreeNode* root) {
        // tc O(n), sc O(n)
        if(root == nullptr) return root;
        vector<vector<int>> vals;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            // 根本没有那么复杂，直接交换就可以了
            TreeNode* cur = que.front(); que.pop();
            swap(cur->left, cur->right);
            if(cur->left) que.push(cur->left);
            if(cur->right) que.push(cur->right);
        }

        return root;
    }
};
