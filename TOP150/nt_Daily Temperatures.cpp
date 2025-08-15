class Solution {
public:
    // 一个很简单的单调栈，从栈底到栈顶是递减
    // 当遇到当前元素大于栈顶元素的时候，就是破坏了单调性，就不停的出栈同时记录
    // 栈中存放下标，同时也能直接操作results数组，记录结果，默认是0
    // tc O(n), sc O(n)
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> results(temperatures.size(), 0);
        stack<int> st;
        st.push(0);

        for(int i = 1; i < temperatures.size(); ++i){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                results[st.top()] = i - st.top();
                st.pop();
            }

            st.push(i);
        }

        return results;
    }
};
