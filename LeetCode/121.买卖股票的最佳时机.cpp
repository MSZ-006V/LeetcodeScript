/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(n, 0));
        dp[0][0] = -prices[0]; // 持有股票的最大收益
        dp[1][0] = 0; // 不持有股票的最大收益

        for(int i = 1; i < prices.size(); ++i){
            dp[0][i] = max(dp[0][i - 1], -prices[i]);
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + prices[i]);
        }
        return dp[1][n - 1];
        
        // vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        // dp[0][0] = -prices[0];
        // dp[0][1] = 1;

        // for(int i = 1; i < prices.size(); ++i){
        //     dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
        //     dp[i][0] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        // }
    }
};
// @lc code=end

