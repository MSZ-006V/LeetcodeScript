/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // 运用lower_bound默认的方法就可以找到，这个方法在#include<algorithm>里面
        
        int v1 = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        // 这个if语句很重要，主要判断这个元素是否在这个数组中
        if(v1 == nums.size() || nums[v1] != target) return {-1, -1};
        int v2 = lower_bound(nums.begin(), nums.end(), target + 1) - nums.begin();
        return {v1, v2 - 1};
    }
};
// @lc code=end

