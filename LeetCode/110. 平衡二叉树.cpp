class Solution {
    int get_height(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int left_h = get_height(node->left);
        int right_h = get_height(node->right);
        if (left_h == -1 || right_h == -1 || abs(left_h - right_h) > 1) {
            return -1;
        }
        return max(left_h, right_h) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        return get_height(root) != -1;
    }
};