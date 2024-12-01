/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 前缀和，也可以通过，但是会超时
        // vector<int> prefix_sum;
        // prefix_sum.push_back(0);
        // int sum = 0;
        // for(int i = 0; i < nums.size(); ++i){
        //     sum += nums[i];
        //     prefix_sum.push_back(sum);
        // }
        // int result = nums[0];
        // for(int i = 1; i < prefix_sum.size(); ++i){
        //     for(int j = 0; j < i; ++j){
        //         if(prefix_sum[i] - prefix_sum[j] > result){
        //             result = prefix_sum[i] - prefix_sum[j];
        //         }
        //     }
        // }
        // return result;

        // 直接使用动态规划就可以了
        // time complexity is O(n), space complexity is O(n)
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int maxsum = nums[0];

        for(int i = 1; i < nums.size(); ++i){
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if(dp[i] > maxsum) maxsum = dp[i];
        }

        return maxsum;

        // time complexity is O(n), space complexity is O(1)
        int res = INT_MIN;
        int sum = 0;

        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            if(sum < nums[i]){
                sum = nums[i];
            }
            if(sum > res){
                res = sum;
            }
        }

        return res;
    }
};
// @lc code=end

