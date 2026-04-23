// 具体地，在进行搜索时，搜索状态除了当前节点之外，还需要存储该节点的祖父节点和父节点，
// 即三元组 (grandparent, parent, node)。
// 如果节点 grandparent 的值为偶数，那么就将节点 node 的值加入答案。
// 在这之后，我们继续搜索节点 node 的左孩子 (parent, node, node.left) 
// 以及右孩子 (parent, node, node.right)，直到搜索结束。

class Solution {
private:
    int ans = 0;
    
public:
    void dfs(TreeNode* grandparent, TreeNode* parent, TreeNode* node) {
        if (!node) {
            return;
        }
        if (grandparent->val % 2 == 0) {
            ans += node->val;
        }
        dfs(parent, node, node->left);
        dfs(parent, node, node->right);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        if (root->left) {
            dfs(root, root->left, root->left->left);
            dfs(root, root->left, root->left->right);
        }
        if (root->right) {
            dfs(root, root->right, root->right->left);
            dfs(root, root->right, root->right->right);
        }
        return ans;
    }
};
