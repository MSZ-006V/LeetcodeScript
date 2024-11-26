/*
 * @lc app=leetcode id=628 lang=cpp
 *
 * [628] Maximum Product of Three Numbers
 */

// @lc code=start
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // 因为考虑到负数的情况，这题也不是要找连续的子数组
        // 直接排序后，看是最大的三个数相乘大，还是最小的两个数和最大数相乘结果大（赌最小的两个数是负数，特别大的情况）
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return max(nums[0] * nums[1] * nums[n - 1], nums[n - 1] * nums[n - 2] * nums[n - 3]);
    }
};
// @lc code=end

