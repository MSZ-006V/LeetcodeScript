/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
class Solution {
public:
    int count;
    int target;
    unordered_map<long long, int> ht;
    
    void traversal(TreeNode* root, long long sum){
        if(root == nullptr){
            return;
        }
        sum += root->val;
        if(ht.find(sum - target) != ht.end()){
            count += ht[sum - target];
        }

        ht[sum]++;
        traversal(root->left, sum);
        traversal(root->right, sum);
        ht[sum]--; // 注意这里需要回溯，因为题目要求只能从父节点到子节点，左子树的计算的前缀和不能用到右子树

    }

    int pathSum(TreeNode* root, int targetSum) {
        count = 0;
        target = targetSum;
        if(root == nullptr){
            return 0;
        }
        ht[0] = 1;
        traversal(root, 0);
        // for(auto item:ht){
        //     cout << item.first << ' ' << item.second << endl;
        // }
        return count;
    }
};
// @lc code=end

