/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        stack<int> st;
        heights.push_back(0);
        heights.insert(heights.begin(), 0);
        st.push(0);

        for(int i = 1; i < heights.size(); ++i){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int mid = st.top(); st.pop();
                if(!st.empty()){
                    int right = i;
                    int left = st.top();
                    int width = right - left - 1;
                    int high = heights[mid];
                    result = max(result, width * high);
                }
            }
            st.push(i);
        }

        return result;
    }
};
// @lc code=end

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 和42接雨水实际上是一样的
        // 前 -> 后, 栈底 到 栈顶 递增
        stack<int> st;
        st.push(0);
        heights.push_back(0);
        heights.insert(heights.begin(), 0);
        int res = 0;

        for(int i = 1; i < heights.size(); ++i){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int mid = st.top(); st.pop();
                if(!st.empty()){
                    int right = i;
                    int left = st.top();
                    int h = heights[mid];
                    int w = right - left - 1;
                    res = max(res, w * h);
                }
            }
            st.push(i);
        }

        return res;
    }
};

