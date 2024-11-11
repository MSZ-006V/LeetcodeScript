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
    void traversal(TreeNode* root, 
    priority_queue<int, vector<int>, function<bool(int, int)>>& pq, 
    int k){
        if(root == nullptr) return;
        pq.push(root->val);
        if(pq.size() > k){
            pq.pop();
        }

        if(root->left){
            traversal(root->left, pq, k);
        }
        if(root->right){
            traversal(root->right, pq, k);
        }
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        // 使用优先队列也可以，减小空间，但是时间复杂度仍然差不多
        // 要看看如何才能不遍历整棵树
        if(root == nullptr) return {};
        auto cmp = [&](const int a, const int b){
            if(abs(target - a) == abs(target - b)){
                return a > b?true:false;
            }
            return abs(target - a) < abs(target - b)?true:false;
        };
        priority_queue<int, vector<int>, function<bool(int, int)>> pq(cmp);
        
        traversal(root, pq, k);

        // 注释的方法也可以
        // sort(result.begin(), result.end(), [&](int a, int b){
        //     if(abs(target - a) == abs(target - b)){
        //         return a > b?true:false;
        //     }
        //     return abs(target - a) < abs(target - b)?true:false;
        // });
        // while(result.size() > k){
        //     result.pop_back();
        // } 

        vector<int> res;
        while(pq.size() > 0){
            res.insert(res.begin(), pq.top());
            pq.pop();
        }
        return res;
    }
};