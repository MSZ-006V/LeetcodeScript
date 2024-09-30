/*
 * @lc app=leetcode id=2390 lang=cpp
 *
 * [2390] Removing Stars From a String
 */

// @lc code=start
class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '*' && st.size() != 0){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        std::string result;
        while(st.size() != 0){
            result += st.top();
            st.pop();
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end

