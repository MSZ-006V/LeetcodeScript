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

// 这道题也可以用序列化+匹配来做，先把两棵树全部序列化，然后相当于找子串问题

class Solution {
public:
    // 这个函数来自nt_Same Binary Tree.cpp
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }
        if (p && q && p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        } else {
            return false;
        }
    }  

    void dfs(TreeNode* root, TreeNode* subroot, bool& res){
        if(root == nullptr) return;

        res |= isSameTree(root, subroot);
        if(root->left) dfs(root->left, subroot, res);
        if(root->right) dfs(root->right, subroot, res);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // 简单的遍历然后判断
        bool res;
        dfs(root, subRoot, res);
        return res;
    }
};
