/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st; // 栈里面存储下标，再用下标来找数就可以了
        vector<int> ans(n, 0);
        for(int i = n - 1; i >= 0; --i){ // 这是从后往前的写法
            int temperature = temperatures[i];
            while(st.size() != 0 && temperature >= temperatures[st.top()]){
                st.pop();
            }
            if(st.size() != 0){ // 此时st.top() > temperature的
                ans[i] = st.top() - i;
            }
            st.push(i);
        }

        // for(int i = 0; i < n; ++i){ // 从前往后的写法
        //     int temperature = temperatures[i];
        //     while(st.size() != 0 && temperature > temperatures[st.top()]){
        //         int j = st.top();
        //         st.pop();
        //         ans[j] = i - j;
        //     }
        //     st.push(i);
        // }
        return ans;
    }
};
// @lc code=end

