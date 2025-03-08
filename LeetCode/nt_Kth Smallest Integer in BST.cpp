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
    // 具体思路就是，对于BST中的某一个节点，它的左子树中的所有节点，都是小于当前节点的，右子树中的所有节点，都是大于当前节点的
    // 所以对于第k小的数，首先先遍历左子树，遍历的时候同时减少k的值，如果在左子树中k变成0了，就说明要找的点是在左子树中，记录值就行
    // 如果左子树所有点都遍历完了还没有变成0，再遍历右子树，继续找，因为是第k小（从最小到目标有k个数，就是第k小）
    // 假设n个数，第k小，就相当于第n - k + 1大，相对应的而已，找第k小和第k大的问题是可以相互转换的（先遍历右子树或者子树）

    // 实际上就是中序遍历，BST中序遍历的结果是一个递增数组，所以中序遍历的第k个元素就是数组中第k小的，所以用tmp[0]来记录遍历了几个元素
    // 当遍历到第k个元素就得到结果了

    void dfs(TreeNode* root, vector<int>& tmp){
        if(root == nullptr) return;

        dfs(root->left, tmp);
        tmp[0]--;
        if(tmp[0] == 0){
            tmp[1] = root->val;
            return;
        }
        dfs(root->right, tmp);

        // 这个就相当于找第k大
        // dfs(root->right, tmp);
        // tmp[0]--;
        // if(tmp[0] == 0){
        //     tmp[1] = root->val;
        //     return;
        // }
        // dfs(root->left, tmp);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> tmp(2);
        tmp[0] = k;
        dfs(root, tmp);
        return tmp[1];
    }
};
