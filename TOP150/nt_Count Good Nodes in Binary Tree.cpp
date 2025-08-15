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
    int node_num;
    void dfs(TreeNode* root, int path_max_val){
        if(root == nullptr) return;
        if(root->val >= path_max_val) node_num++;

        int val = max(root->val, path_max_val);

        dfs(root->left, val);
        dfs(root->right, val);
    }

    int goodNodes(TreeNode* root) {
        node_num = 0;
        if(root == nullptr) return 0;
        int val = root->val; // 因为条件是大于等于，所以最开始的根节点必须算一个，所以把初始val设置成根节点值，保证不会遗漏1个
        dfs(root, val);
        
        return node_num;
    }
};
