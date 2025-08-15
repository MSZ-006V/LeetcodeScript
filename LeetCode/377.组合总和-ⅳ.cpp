/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        for(int i = 0; i < target + 1; ++i){
            for(int j = 0; j < nums.size(); ++j){
                if(i - nums[j] >= 0){
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        // for(auto num : dp){
        //     cout << num << ' ';
        // }
        // cout << endl << "size: " << dp.size();

        return dp[target];
    }
};

class Solution {
public:
    // 做法是一元的
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned> dp(target + 1, 0);
        dp[0] = 1;
        
        for(int i = 1; i < target + 1; ++i){
            for(auto num : nums){
                if(i >= num){
                    dp[i] += dp[i - num];
                }
            }
        }

        return dp[target];
    }
};
// @lc code=end

