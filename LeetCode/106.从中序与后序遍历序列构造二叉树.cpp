/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* traversal(vector<int>& in_order, vector<int>& post_order){
        if(in_order.size() == 0){
            return nullptr;
        }

        int root_val = post_order.back();
        post_order.pop_back();
        TreeNode* root = new TreeNode(root_val);

        if(post_order.size() == 0){
            return root;
        }

        auto it = find(in_order.begin(), in_order.end(), root_val);
        int index = distance(in_order.begin(), it); // 注意这种使用方法

        vector<int> left_inorder(in_order.begin(), in_order.begin() + index);
        vector<int> right_inorder(in_order.begin() + index + 1, in_order.end());

        vector<int> left_postorder(post_order.begin(), post_order.begin() + left_inorder.size());
        vector<int> right_postorder(post_order.begin() + left_inorder.size(), post_order.end());

        root->left = traversal(left_inorder, left_postorder);
        root->right = traversal(right_inorder, right_postorder);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0){
            return nullptr;
        }
        TreeNode* root = traversal(inorder, postorder);
        return root;
    }
};
// @lc code=end

