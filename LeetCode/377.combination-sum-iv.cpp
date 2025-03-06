/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        
        // 遍历物品在外，就是求组合数，不同顺序视为相同方案
        // for(auto num : nums){
        //     for(int i = num; i < target + 1; ++i){
        //         dp[i] += dp[i - num];
        //     }
        // }

        // 遍历背包在外，遍历物品在内，就是求排列数，不同顺序视为不同方案
        for(int i = 0; i < target + 1; ++i){
            for(auto num : nums){
                if(i - num >= 0){
                    dp[i] += dp[i - num];
                }
            }
        }

        return dp[target];
    }
};
// @lc code=end

