/*
 * @lc app=leetcode.cn id=331 lang=cpp
 *
 * [331] 验证二叉树的前序序列化
 */

// @lc code=start
class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string s;
        vector<string> st;
        while(getline(ss, s, ',')){
            st.push_back(s);

            while(st.size() >= 3 
            && st[st.size() - 1] == "#"
            && st[st.size() - 2] == "#"
            && st[st.size() - 3] != "#"){
                st.pop_back();st.pop_back();st.pop_back();
                st.push_back("#");
            }
        }

        for(auto num : st){
            cout << num << ' ';
        }

        if(st.size() == 1 && st[0] == "#") return true;
        return false;
    }
};
// @lc code=end

