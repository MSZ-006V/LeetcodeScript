class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // tc O(n), sc O(n)，可以做到O(1)
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(n, 0));
        // dp[0][i]代表持有股票，就是买入
        // dp[1][i]代表不持有股票
        dp[0][0] = -prices[0];
        dp[1][0] = 0;
        for(int i = 1; i < n; ++i){
            dp[0][i] = max(dp[0][i - 1], -prices[i]);
            dp[1][i] = max(dp[0][i - 1] + prices[i], dp[1][i - 1]);
        }

        return dp[1][n - 1];
    }
};
