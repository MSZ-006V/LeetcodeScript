/*
 * @lc app=leetcode id=2334 lang=cpp
 *
 * [2334] Subarray With Elements Greater Than Varying Threshold
 */

// @lc code=start
class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        // 这题是利用单调栈，对于下标为i的元素nums[i]，以nums[i]作为区间的起始，找到
        // 左边第一个比它小的和右边第一个比它小的，然后就能得到一个区间，这个区间中所有的
        // 数都是大于等于nums[i]的，然后也能得到区间长度，判断nums[i]与threshhold / k的大小即可
        // 如果找到一个答案，立即返回。进阶版可以记录，找出最大的区间长度
        int n = nums.size();
        stack<int> st;
        int left[n];
        // left[i] 为左侧小于 nums[i] 的最近元素位置（不存在时为 -1）
        for(int i = 0; i < n; ++i){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            left[i] = st.empty()?-1:st.top();
            st.push(i);
        }

        st = stack<int>();
        int right[n];
        // right[i] 为右侧小于 nums[i] 的最近元素位置（不存在时为 n）
        for(int i = n - 1; i > -1; --i){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            right[i] = st.empty()?n:st.top();
            st.push(i);
        }

        for(int i = 0; i < n; ++i){
            int k = right[i] - left[i] - 1;
            if(nums[i] > threshold / k) return k;
        }

        return -1;
    }
};
// @lc code=end

