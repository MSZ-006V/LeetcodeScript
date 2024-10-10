/*
 * @lc app=leetcode id=2563 lang=cpp
 *
 * [2563] Count the Number of Fair Pairs
 */

// @lc code=start
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        // 先排序，然后找最大最小的范围就可以
        // 需要去重
        long long cnt = 0;
        for(int i = 0; i < nums.size(); ++i){
            int left = lower - nums[i];
            int right = upper - nums[i];
            // 下面这么写是为了保证去重
            auto _left = ranges::lower_bound(nums.begin() + i + 1, nums.end(), left);
            auto _right = ranges::upper_bound(nums.begin() + i + 1, nums.end(), right);
            cnt += (_right - _left);
        }
        return cnt;
    }
};
// @lc code=end

