/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int ans;
    int traversal(TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        int left = traversal(root->left);
        int right = traversal(root->right);
        ans = max(ans, left + right + 1);
        return max(left, right) + 1;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        ans = 1;
        traversal(root);
        return ans - 1;

    }
};
// @lc code=end

