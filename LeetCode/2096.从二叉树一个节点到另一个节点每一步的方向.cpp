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
    string p_path;
    string q_path;
    string dfs(TreeNode* root, int p, int q, string path){
        if(root == nullptr) return "";
        if(root->val == p){
            p_path = path;
        }
        if(root->val == q){
            q_path = path;
        }

        string left = dfs(root->left, p, q, path + "L");
        string right = dfs(root->right, p, q, path + "R");

        return path;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // tc O(n), sc O(n)，n 是树的节点数，最坏情况下树是链状的，递归深度就是 n
        // 首先计算出从根到p，q的路径
        // 随后查看前缀和，前缀和重复的部分的最后一个位置就是LCA的位置
        // 从那个位置开始，p和q的路径不同，此时从那个位置开始，把p的路径转换为U，再拼接q的路径就是答案
        p_path = "";
        q_path = "";
        dfs(root, startValue, destValue, "");
        cout << p_path << ", " << q_path << endl;
        int i = 0;
        while(i < min((int)p_path.size(), (int)q_path.size()) && p_path[i] == q_path[i]){
            i++;
        }

        return string(p_path.size() - i, 'U') + q_path;
    }
};