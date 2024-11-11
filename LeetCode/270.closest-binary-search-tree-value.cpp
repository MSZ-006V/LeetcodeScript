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
private:
    int result;
public:
    void bst(TreeNode* root, double target){
        if(root == nullptr) return;
        result = abs(target - result) > abs(target - root->val)?root->val:result;
        if(abs(target - result) == abs(target - root->val)){
            result = result < root->val?result:root->val;
        }

        if(target <= root->val){
            bst(root->left, target);
        }
        else{
            bst(root->right, target);
        }
    }
    int closestValue(TreeNode* root, double target) {
        if(root == nullptr) return 0;
        result = root->val;
        bst(root, target);
        return result;
    }
};