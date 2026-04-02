class Solution
{
public:
    vector<string> BinaryTreePaths(TreeNode *root)
    {
        vector<string> result;
        if (root == nullptr)
        {
            return result;
        }
        // 调用拆分出来的辅助函数
        Dfs(root, "", result);
        return result;
    }

private:
    // 将逻辑拆分为私有成员函数
    // 使用 const string& path 还是 string path 取决于是否需要显式回溯
    void Dfs(TreeNode *node, string path, vector<string> &result)
    {
        if (node == nullptr)
        {
            return;
        }

        // 记录当前节点值
        path += to_string(node->val);

        // 如果是叶子节点，保存路径
        if (node->left == nullptr && node->right == nullptr)
        {
            result.push_back(path);
            return;
        }

        // 非叶子节点，继续递归
        path += "->";
        Dfs(node->left, path, result);
        Dfs(node->right, path, result);
    }
};
