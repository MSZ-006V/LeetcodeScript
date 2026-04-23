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

// 自顶向下
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        auto dfs = [&](this auto&& dfs, TreeNode* node, int depth) -> void {
            if (node == nullptr) {
                return;
            }
            if (depth == ans.size()) { // 这个深度首次遇到
                ans.push_back(node->val);
            }
            dfs(node->right, depth + 1); // 先递归右子树，保证首次遇到的一定是最右边的节点
            dfs(node->left, depth + 1);
        };
        dfs(root, 0);
        return ans;
    }
};

