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
    // tc O(n), sc O(n)
    // leetcode 124相同的做法，最优方案
    int traversal(TreeNode* root, int& sum){
        if(root == nullptr) return 0;

        int l = traversal(root->left, sum);
        int r = traversal(root->right, sum);

        int v1 = max(l, r) + root->val;
        int v2 = max(v1, l + r + root->val);
        sum = max(sum, v2);

        if(v1 < 0) return 0;
        return v1;
    }
    int maxPathSum(TreeNode* root) {
        if(root == nullptr) return 0;
        int sum = INT_MIN;
        traversal(root, sum);
        return sum;
    }
};
