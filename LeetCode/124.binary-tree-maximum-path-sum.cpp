/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 */

// @lc code=start
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
    int traversal(TreeNode* root, int& res){
        // 时间复杂度和空间复杂度都是O(n)的
        // 不解释连招和不解释全局变量，看题目来解决就行
        // 用全部变量记录暂时的最大值就行
        if(root == nullptr) return 0;

        int left = traversal(root->left, res);
        int right = traversal(root->right, res);

        // 代表不以当前root作为连接左右子树的中转点的最大路径值，选左右子树最大的
        int nas_root = max(left, right) + root->val;
        // 后面那个代表以以当前root作为连接左右子树的中转点的最大路径值，所以把左右子树都加起来
        int v = max(nas_root, left + right + root->val);
        // 然后求出来一个最大的v值，然后刷新res全局变量
        res = max(res, v);

        // 最后返回是有说法的，返回要返回nas_root的值，表示不以当前节点为中转点，所以如果是小于零的，那直接扔掉
        // 这个结果就好了，对上面求最大值肯定是没用的，否则返回一个正的值
        if(nas_root < 0) return 0; 
        return nas_root;
    }

    int traversal_optimial(TreeNode* root, int& res){
        // 下面这个写法也是可以的，一个意思
        if(root == nullptr) return 0;

        int left = traversal(root->left, res);
        int right = traversal(root->right, res);

        // 代表不以当前root作为连接左右子树的中转点的最大路径值，选左右子树最大的
        int nas_root = max(left, right) + root->val;
        // 后面那个代表以以当前root作为连接左右子树的中转点的最大路径值，所以把左右子树都加起来
        // 然后求出来一个最大的v值，然后刷新res全局变量
        res = max(res, left + right + root->val);

        // 最后返回是有说法的，返回要返回nas_root的值，表示不以当前节点为中转点，所以如果是小于零的，那直接扔掉
        // 这个结果就好了，对上面求最大值肯定是没用的，否则返回一个正的值
        if(nas_root < 0) return 0; 
        return nas_root;
    }
    int maxPathSum(TreeNode* root) {
        if(root == nullptr) return 0;
        // 把res初始化为最小值，保证例子（只有-3根节点这种情况是正确的）
        int res = INT_MIN;
        traversal_optimial(root, res);

        return res;
    }
};
// @lc code=end

