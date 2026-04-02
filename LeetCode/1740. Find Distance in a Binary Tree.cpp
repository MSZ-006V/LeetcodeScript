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
    // similar to 1123，先找到p和q的路径，然后找到它们的LCA的位置，最后计算距离
    string p_path;
    string q_path;
    string dfs(TreeNode* root, int p, int q, string path){
        if(root == nullptr) return "";
        if(root->val == p){
            p_path = path;
        }
        if(root->val == q){
            q_path = path;
        }

        string left = dfs(root->left, p, q, path + "L");
        string right = dfs(root->right, p, q, path + "R");

        return path;
    }
    int findDistance(TreeNode* root, int p, int q) {
        p_path = "";
        q_path = "";
        dfs(root, p, q, "");
        cout << p_path << ", " << q_path << endl;
        int i = 0;
        while(i < min((int)p_path.size(), (int)q_path.size()) && p_path[i] == q_path[i]){
            i++;
        }

        return p_path.size() - i + q_path.size() - i;
    }
};

// 其他方法
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
    int dfs(TreeNode* node, const int &p, const int &q, int depth){
        if(!node) return -1;

        int left = dfs(node->left, p, q, depth+1);
        int right = dfs(node->right, p, q, depth+1);

        if(left >= 0 && right >= 0)
            return (left+right-depth*2);
        if(node->val == p || node->val == q){
            if(left >= 0)
                return left - depth;
            else if(right >= 0)
                return right - depth;
            else
                return depth;
        }

        if(left >= 0) return left;
        if(right >= 0) return right;

        return -1;
    }

    int findDistance(TreeNode* root, int p, int q) {
        if(p == q) return 0;
        return dfs(root, p, q, 0);
    }
};