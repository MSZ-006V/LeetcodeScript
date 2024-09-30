/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool isFind;
    int target;
    void traversal(TreeNode* root, int sum){
        sum += root->val;
        if(root->right == nullptr && root->left == nullptr){
            if(sum == target){
                isFind = true;
            }
            return;
        }
        
        if(root->left){
            traversal(root->left, sum);
        }
        if(root->right){
            traversal(root->right, sum);
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return false;
        }
        isFind = false;
        target = targetSum;
        traversal(root, 0);
        return isFind;
    }
};
// @lc code=end

