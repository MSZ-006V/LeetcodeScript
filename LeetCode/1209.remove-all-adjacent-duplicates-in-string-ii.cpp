/*
 * @lc app=leetcode id=1209 lang=cpp
 *
 * [1209] Remove All Adjacent Duplicates in String II
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s, int k) {
        // time complexity is O(n), space complexity is O(n)
        // 如果当年s[i]和s[i - 1]不一样，就多放入一个1
        // 如果一样，就先把栈顶元素+1，然后看是否数量到k，如果到就删除，然后调整i指针
        // 这个方法很不错，删除后同时调整i指针就可以

        stack<int> st;
        for(int i = 0; i < s.size(); ++i){
            if(i == 0 || s[i] != s[i - 1]){
                st.push(1);
            }
            else{
                st.top()++;
                if(st.top() == k){
                    st.pop();
                    s.erase(i - k + 1, k);
                    i = i - k;
                }
            } 

        }
        return s;
    }
};
// @lc code=end

