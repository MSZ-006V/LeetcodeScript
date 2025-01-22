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
    void inorder(TreeNode* root, vector<int>& path){
        if(root == nullptr) return;

        inorder(root->left, path);
        path.push_back(root->val);
        inorder(root->right, path);
    }

    bool isValidBST(TreeNode* root) {
        // 判断是否是BST，正常中序遍历结果数组是一个递增的数组，只需要判断是否单调递增
        if(root == nullptr) return true;
        vector<int> result;
        inorder(root, result);

        for(int i = 1; i < result.size(); ++i){
            if(result[i] <= result[i - 1]) return false;
        }

        return true;
    }
};

class Solution {
public:
    // DFS方法
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);
    }

    bool valid(TreeNode* node, long left, long right) {
        if (!node) {
            return true;
        }
        if (!(left < node->val && node->val < right)) {
            return false;
        }
        return valid(node->left, left, node->val) &&
               valid(node->right, node->val, right);
    }
};
