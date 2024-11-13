/*
 * @lc app=leetcode id=1530 lang=cpp
 *
 * [1530] Number of Good Leaf Nodes Pairs
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
    vector<int> dfs(TreeNode* root, int distance, int& ans){
        // 找到叶子节点的最近公共子父节点
        if(root == nullptr) return {};
        if(root->left == nullptr && root->right == nullptr) return {0};

        vector<int> ret;
        auto left = dfs(root->left, distance, ans);
        for(auto& v : left){
            if(++v > distance) continue;
            ret.push_back(v);
        }

        auto right = dfs(root->right, distance, ans);
        for(auto& v : right){
            if(++v > distance) continue;
            ret.push_back(v);
        }

        for(auto l : left){
            for(auto r : right){
                ans = ans + (l + r <= distance);
            }
        }

        return ret;
    }
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        dfs(root, distance, ans);
        return ans;
    }
};
// @lc code=end

