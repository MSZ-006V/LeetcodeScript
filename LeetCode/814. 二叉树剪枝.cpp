class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        // 这里判断了以该节点为根节点的子树里面的1的个数，假如root-val也是0，那么这里取反就会是1，返回nullptr
        // 代表这个子树一个1都没有，那么就应该删除
        if (!root->left && !root->right && !root->val) {
            return nullptr;
        }
        return root;
    }   
};
