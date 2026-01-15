/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    void dfs(TreeNode* node, TreeNode* par) {
        if (!node) return;
        parent[node] = par;
        dfs(node->left, node);
        dfs(node->right, node);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // 将树变为一个无向图，然后用BFS来找即可
        dfs(root, nullptr);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        int dist = 0;

        while (!q.empty()) {
            int sz = q.size();
            if (dist == k) break;

            while (sz--) {
                auto cur = q.front(); q.pop();

                for (TreeNode* nei : {cur->left, cur->right, parent[cur]}) {
                    if (nei && !visited.count(nei)) {
                        visited.insert(nei);
                        q.push(nei);
                    }
                }
            }
            dist++;
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};