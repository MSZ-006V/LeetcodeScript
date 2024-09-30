/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int right = nums.size() - 1;
        int left = 0;
        int mid = (right + left) / 2;
        return nums[mid];
    }
};
// @lc code=end

