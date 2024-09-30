/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
private:
    vector<vector<int>> result_path;
public:
    void findPath(TreeNode* root, int target, vector<int>& path, int sum){
        if(root->left == nullptr && root->right == nullptr){
            if(sum == target){
                result_path.push_back(path);
            }
            return;
        }

        if(root->left){
            sum += root->left->val;
            path.push_back(root->left->val);
            findPath(root->left, target, path, sum);
            sum -= root->left->val;
            path.pop_back();
        }
        if(root->right){
            sum += root->right->val;
            path.push_back(root->right->val);
            findPath(root->right, target, path, sum);
            sum -= root->right->val;
            path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return {};
        vector<int> result;
        result.push_back(root->val);
        int sum = root->val;
        findPath(root, targetSum, result, sum);
        return result_path;
    }  
};
// @lc code=end

