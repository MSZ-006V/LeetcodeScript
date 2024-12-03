/*
 * @lc app=leetcode id=1944 lang=cpp
 *
 * [1944] Number of Visible People in a Queue
 */

// @lc code=start
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        // 典型单调栈题目，栈底到栈尾是单调递减的
        // monotonic stack
        int n = heights.size();
        stack<int> st;
        vector<int> result(n, 0);

        for(int i = 0; i < n; ++i){
            // 栈中存储下标
            while(!st.empty() && heights[st.top()] < heights[i]){ // 如果有小的，就直接弹出多余的元素
                result[st.top()]++;
                st.pop();
            }

            // 下面这个if非常重要，最开始写一直不行就是因为少一个if
            // 因为经过上面的while循环后，st.top()对应的元素肯定是大于当前要进栈的元素的
            // 所以把结果中对应的下标加一，代表能看到这个元素
            // 其实也是一种类似模拟，但是比较巧妙，要仔细地进行计算才能发现这个小方面
            if(!st.empty()){
                result[st.top()]++;
            }
            
            st.push(i);
        }

        return result;
    }
};
// @lc code=end

