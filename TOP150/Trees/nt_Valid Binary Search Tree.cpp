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
        if (node == nullptr) {
            return true;
        }
        // left < node->val && right > node->val 是一颗树是BST的必要条件
        // 取反就代表不满足条件，返回false
        if (!(left < node->val && node->val < right)) {
            return false;
        }
        // 递归检查
        return valid(node->left, left, node->val) &&
               valid(node->right, node->val, right);
    }
    // left和right分别代表当前节点的左边界和右边界，初始值分别是负无穷和正无穷
    // 每次递归检查当前节点的值是否在(left, right)范围内，如果不满足条件就返回false
    // 因为需要保证左子树的所有节点都小于当前节点，右子树的所有节点都大于当前节点
    // 所以在递归检查左子树时更新右边界为当前节点的值，在递归检查右子树时更新左边界为当前节点的值
};
