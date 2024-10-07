/*
 * @lc app=leetcode id=2529 lang=cpp
 *
 * [2529] Maximum Count of Positive Integer and Negative Integer
 */

// @lc code=start
class Solution {
public:
    int bs(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(target > nums[mid]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return left;
    }
    int maximumCount(vector<int>& nums) {
        int r1 = bs(nums, 0); // 找到小于0的数的最右边的边界
        int r2 = bs(nums, 1); // 找到大于0的数的最左边的边界
        // 0~r1就是负数的范围，r2~end就是正数的范围
        
        return max(r1, static_cast<int>(nums.size()) - r2);
    }
};
// @lc code=end

