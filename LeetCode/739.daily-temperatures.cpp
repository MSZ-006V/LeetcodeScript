/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> ans(n, 0);

        for(int i = 0; i < n; ++i){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                int j = st.top(); st.pop();
                ans[j] = i - j;
            }
            st.push(i);
        }

        return ans;
    }
};
// @lc code=end

