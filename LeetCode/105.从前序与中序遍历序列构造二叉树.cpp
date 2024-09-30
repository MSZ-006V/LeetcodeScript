/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* traversal(vector<int>& pre_order, vector<int>& in_order){
        if(in_order.size() == 0){
            return nullptr;
        }
        
        int root_val = pre_order[0];
        TreeNode* root = new TreeNode(root_val);

        if(pre_order.size() == 1){
            return root;
        }

        auto it = find(in_order.begin(), in_order.end(), root_val);
        int index = distance(in_order.begin(), it);

        vector<int> left_inorder(in_order.begin(), in_order.begin() + index);
        vector<int> right_inorder(in_order.begin() + index + 1, in_order.end());

        vector<int> left_preorder(pre_order.begin() + 1, pre_order.begin() + 1 + left_inorder.size());
        vector<int> right_preorder(pre_order.begin() + 1 + left_inorder.size(), pre_order.end());

        root->left = traversal(left_preorder, left_inorder);
        root->right = traversal(right_preorder, right_inorder);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0){
            return nullptr;
        }
        TreeNode* root = traversal(preorder, inorder);
        return root;
    }
};
// @lc code=end

