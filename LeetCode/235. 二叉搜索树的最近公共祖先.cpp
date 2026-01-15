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
    // leetcode 235 二叉搜索树的最近公共祖先
    // 我这个是普通二叉树的LCA，这道题是BST的LCA，可以有简化的部分
    TreeNode* find(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr || root == p || root == q) return root;
        
        TreeNode* left = find(root->left, p, q);
        TreeNode* right = find(root->right, p, q);
        if(left != nullptr && right != nullptr){
            return root;
        }
        else if(left == nullptr && right != nullptr){
            return right;
        }
        else if(left != nullptr && right == nullptr){
            return left;
        }
        else{
            return nullptr;
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        TreeNode* node = find(root, p, q);

        return node;
    }
};

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        int x = root->val;
        if (p->val < x && q->val < x) { // p 和 q 都在左子树
            return lowestCommonAncestor(root->left, p, q);
        }
        if (p->val > x && q->val > x) { // p 和 q 都在右子树
            return lowestCommonAncestor(root->right, p, q);
        }
        return root; // 其它
    }
};
