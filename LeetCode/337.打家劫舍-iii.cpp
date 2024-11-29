/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    vector<int> traversal(TreeNode* root){
        if(root == nullptr){
            return {0, 0};
        }

        vector<int> left = traversal(root->left);
        vector<int> right = traversal(root->right);

        int val1 = max(left[0], left[1]) + max(right[0], right[1]); // 不偷当前节点
        int val2 = root->val + left[0] + right[0];

        return {val1, val2};
    }
    int rob(TreeNode* root) {
        if(root == nullptr) return 0;
        vector<int> result = traversal(root);
        
        return max(result[0], result[1]);
    }
};
// @lc code=end

