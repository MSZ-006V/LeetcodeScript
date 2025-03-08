/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
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
    TreeNode* find(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == p || root == q || root == nullptr){
            return root;
        }

        TreeNode* left = find(root->left, p, q);
        TreeNode* right = find(root->right, p, q);
        
        if(left != nullptr && right != nullptr){
            return root;
        }
        else if(left == nullptr && right != nullptr){
            return right;
        }
        else if(left != nullptr && right == nullptr){
            return left;
        }
        return nullptr;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr){
            return nullptr;
        }
        TreeNode* node = find(root, p, q);
        return node;
    }
};
// @lc code=end

