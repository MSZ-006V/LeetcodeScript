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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(p);
        q2.push(q);

        while(!q1.empty() && !q2.empty()){
            TreeNode* curq = q1.front(); q1.pop();
            TreeNode* curp = q2.front(); q2.pop();

            // 主要判断就是下面这两句
            if(!curq && !curp) continue; // curq and curp all nullptr continue;
            if(!curq || !curp || curq->val != curp->val) return false; // 三种情况(1) curq为空curp不为空 (2) curq不为空curp为空 (3) curq, curp不为空，值不等

            q1.push(curq->left); q1.push(curq->right);
            q2.push(curp->left); q2.push(curp->right);
        }

        return true;
    }
};

// DFS版本，主要判断语句也是下面那个if循环
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }
        if (p && q && p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        } else {
            return false;
        }
    }
};