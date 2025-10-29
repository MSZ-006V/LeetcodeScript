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

class Codec {

public:
    // leetcode 297
    // tc O(n), sc O(n)
    // Encodes a tree to a single string.  
    string serialize(TreeNode* root) {
        if(root == nullptr) return "[]";
        
        queue<TreeNode*> que;
        que.push(root);
        string res = "";

        while(!que.empty()){
            TreeNode* cur = que.front(); que.pop();
            if(cur != nullptr){
                res += std::to_string(cur->val) + " ";
                que.push(cur->left);
                que.push(cur->right);
            }
            else{
                res += "null ";
            }
        }
        
        return res;
    }

    // Decodes your encoded data to tree.
    // stoi();
    TreeNode* deserialize(string data) {
        if(data == "[]") return nullptr;

        vector<string> nums;
        std::istringstream ss(data);
        string temp;
        while(getline(ss, temp, ' ')){
            nums.push_back(temp);
        }

        TreeNode* root = new TreeNode(std::stoi(nums[0]));
        queue<TreeNode*> que;
        que.push(root);
        int index = 1;

        while(!que.empty()){
            TreeNode* cur = que.front(); que.pop();

            if(nums[index] != "null"){
                cur->left = new TreeNode(std::stoi(nums[index]));
                que.push(cur->left);
            }
            index++;
            if(nums[index] != "null"){
                cur->right = new TreeNode(std::stoi(nums[index]));
                que.push(cur->right);
            }
            index++;
        }

        return root;
    }
};
