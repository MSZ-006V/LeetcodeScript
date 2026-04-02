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
    int res;
    void find(TreeNode* root, int max_v, int min_v){
        if(root == nullptr) {
            res = max(res, max_v - min_v);
            return;
        }

        max_v = max(max_v, root->val);
        min_v = min(min_v, root->val);
        find(root->left, max_v, min_v);
        find(root->right, max_v, min_v);
    }
    int maxAncestorDiff(TreeNode* root) {
        res = 0;
        find(root, root->val, root->val);

        return res;
    }
};