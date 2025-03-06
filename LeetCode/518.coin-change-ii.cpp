/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change II
 */

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned> dp(amount + 1, 0);
        dp[0] = 1;

        for(auto coin : coins){
            for(int i = coin; i < amount + 1; ++i){
                dp[i] += dp[i - coin];
            }
        }

        return dp[amount];
    }
};
// @lc code=end

