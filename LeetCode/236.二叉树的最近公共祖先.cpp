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
        // 向下一直找，直到找到节点p或者q或者一个空节点
        if(root == p || root == q || root == nullptr){
            return root;
        }

        TreeNode* left = find(root->left, p, q);
        TreeNode* right = find(root->right, p, q);
        
        // 如果返回的left和right都不是空节点，就返回当前root节点
        // 如果有一个不为空另一个为空，返回不为空那个
        // 如果2个都为空，就返回nullptr
        // 这样能找到公共父节点，包括所有的2种情况都考虑到了
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

