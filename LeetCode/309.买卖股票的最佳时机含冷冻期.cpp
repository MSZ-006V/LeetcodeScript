class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2) return 0;
        vector<vector<int>> dp(2, vector<int>(n, 0));
        // dp[0][i]代表持有股票，就是买入
        // dp[1][i]代表不持有股票
        dp[0][0] = -prices[0];
        dp[1][0] = 0;
        dp[0][1] = max(dp[0][0], -prices[1]);
        dp[1][1] = max(dp[1][0], dp[0][0] + prices[1]);

        for(int i = 2; i < n; ++i){
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 2] - prices[i]);
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + prices[i]);
        }

        return dp[1][n - 1];
    }
};