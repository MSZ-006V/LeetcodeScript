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
    // 这道题的解法比较精巧，是有递有归类型的
    // tc O(n)，sc O(n)，n 是树的节点数，最坏情况下树是链状的，递归深度就是 n
    pair<TreeNode*, int> dfs(TreeNode* root){
        if(root == nullptr){
            return {nullptr, 0};
        }

        auto [left, left_h] = dfs(root->left);
        auto [right, right_h] = dfs(root->right);

        if(left_h > right_h){
            return {left, left_h + 1};
        }
        else if(left_h < right_h){
            return {right, right_h + 1};
        }

        return {root, left_h + 1};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
};