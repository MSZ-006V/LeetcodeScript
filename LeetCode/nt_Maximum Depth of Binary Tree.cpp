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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int height = 0;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            int size = que.size();
            height++;
            for(int i = 0; i < size; ++i){
                TreeNode* cur = que.front(); que.pop();
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }

        return height;
    }
};

class Solution {
public:
    // 递归DFS
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
