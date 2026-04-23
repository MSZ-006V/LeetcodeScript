// 更新左儿子（右儿子）为递归左儿子（右儿子）的返回值。
// 如果当前节点被删除，那么就检查左儿子（右儿子）是否被删除，如果没被删除，就加入答案。
// 如果当前节点被删除，返回空节点，否则返回当前节点。
// 最后，如果根节点没被删除，把根节点加入答案。

class Solution {
    vector<TreeNode*> ans;
    unordered_set<int> s;

    TreeNode* dfs(TreeNode *node) {
        if (node == nullptr) return nullptr;

        node->left = dfs(node->left);
        node->right = dfs(node->right);

        if (!s.count(node->val)) return node;
        if (node->left) ans.push_back(node->left);
        if (node->right) ans.push_back(node->right);

        return nullptr;
    }

public:
    vector<TreeNode*> delNodes(TreeNode *root, vector<int> &to_delete) {
        for (int x : to_delete) s.insert(x);
        if (dfs(root)) ans.push_back(root);
        return ans;
    }
};
