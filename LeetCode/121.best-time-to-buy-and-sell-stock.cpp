/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(prices.size(), 0));
        dp[0][0] = -prices[0]; // 持有股票
        dp[1][0] = 0; // 不持有股票

        for(int i = 1; i < prices.size(); ++i){
            dp[0][i] = max(dp[0][i - 1], -prices[i]);
            dp[1][i] = max(dp[0][i - 1] + prices[i], dp[1][i - 1]);
        }

        return dp[1][prices.size() - 1];
    }
};
// @lc code=end

