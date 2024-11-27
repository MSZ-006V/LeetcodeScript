/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // 这题就是遍历一个树，生成一个字符串，然后再根据这个字符串还原出这个树
    // 使用的方法是层次遍历，由于要保存所有信息，所以尽管遍历到空节点，也要加一个null来表示是空的
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr){
            return "[]";
        }

        queue<TreeNode*> que;
        que.push(root);
        string result = "";

        while(!que.empty()){
            TreeNode* node = que.front(); 
            que.pop();
            if(node != nullptr){
                result += std::to_string(node->val) + " ";
                que.push(node->left);
                que.push(node->right);
            }
            else{
                result += "null "; // 虽然空但是也要加，保证还原的正确
            }
        }
    
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "[]" || data == "null") return nullptr;

        vector<string> words;
        std::istringstream iss(data);
        string temp;
        while(getline(iss, temp, ' ')){
            words.push_back(temp);
        }

        TreeNode* root = new TreeNode(std::stoi(words[0]));
        queue<TreeNode*> que;
        que.push(root);
        int index = 1;
        // 还原的时候直接用index访问就可以了，顺序访问数组，遇到空的就跳过，因为默认就是nullptr，不需要赋值成nullptr

        
        while(!que.empty()){
            TreeNode* node = que.front();
            que.pop();
            if(words[index] != "null"){
                node->left = new TreeNode(std::stoi(words[index]));
                que.push(node->left);
            }
            index++;
            if(words[index] != "null"){
                node->right = new TreeNode(std::stoi(words[index]));
                que.push(node->right);
            }
            index++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

