/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */

// @lc code=start
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
    vector<int> result;
    void traversal(TreeNode* root){
        if(root == nullptr)
            return;

        result.push_back(root->val);
        traversal(root->left);
        traversal(root->right);
    }

    TreeNode* modify_tree(TreeNode* root, int index){
        if(index == result.size()){
            return nullptr;
        }

        TreeNode* node = new TreeNode(result[index]);
        node->right = modify_tree(node->right, index + 1);
        node->left = nullptr;
        return node;

    }
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        traversal(root);

        for(int i = 0; i < result.size(); ++i){
            cout << result[i] << ' ';
        }

        root->right = modify_tree(root->right, 1);
        root->left = nullptr;
        
    }
};
// @lc code=end

