/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int val = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(2 * val + nums[i] == sum){
                return i;
            }
            val += nums[i];
        }
        return -1;
    }
};
// @lc code=end

