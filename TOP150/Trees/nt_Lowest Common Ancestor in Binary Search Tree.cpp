// leetcode 236 Lowest common ancestor 最近公共祖先

class Solution {
public:
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 这个查找方式比较巧妙，用到了BST的性质，左小右大，可以学习一下
        if(!root || !p || !q){
            return nullptr;
        }

        if(max(p->val, q->val) < root->val){
            return LCA(root->left, p, q);
        } 
        else if(min(p->val, q->val) > root->val){
            return LCA(root->right, p, q);
        } 
        else{
            return root;
        }
    }
};

// LCA in common tree
class Solution {
public:
    TreeNode* find(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr || root == p || root == q) return root;

        TreeNode* left = find(root->left, p, q);
        TreeNode* right = find(root->right, p, q);

        if(left == nullptr && right == nullptr){
            return nullptr;
        }
        else if(left == nullptr && right != nullptr){
            return right;
        }
        else if(left != nullptr && right == nullptr){
            return left;
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return find(root, p, q);
    }
};