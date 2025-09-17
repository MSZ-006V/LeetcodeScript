/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int answer = 0;
        st.push(0);
        for(int i = 1; i < height.size(); ++i){
            if(height[i] <= height[st.top()]){
                st.push(i);
            }
            else{
                while(st.size() != 0 && height[i] > height[st.top()]){
                    int mid = st.top();st.pop();
                    // st.top()是左边，i是右边，mid是底
                    if(st.size() != 0){
                        int h = min(height[st.top()], height[i]) - height[mid];
                        int w = i - st.top() - 1;
                        answer += w * h;
                    }
                }
                st.push(i);
            }
        }

        return answer;
    }
};
// @lc code=end

