/*
 * @lc app=leetcode id=1283 lang=cpp
 *
 * [1283] Find the Smallest Divisor Given a Threshold
 */

// @lc code=start
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        // 麻烦的地方就是每一次查找，都要对于数组内所有元素算一遍
        // 思路很简单，就是在一个有限的区间不断地查找就可以
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            int total = 0;
            for(auto num : nums){
                total += (num - 1) / mid + 1;
            }
            if(total <= threshold){
                right = mid - 1;
                ans = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return ans;
    }
};
// @lc code=end

