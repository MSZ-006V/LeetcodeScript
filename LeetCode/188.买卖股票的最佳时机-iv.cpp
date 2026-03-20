#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;

        int n = prices.size();

        // dp[j][i]：第 j 个状态，第 i 天
        vector<vector<int>> dp(2 * k, vector<int>(n, 0));

        // 初始化（第 0 天）
        for (int j = 0; j < 2 * k; j++) {
            if (j % 2 == 0) { // 持有
                dp[j][0] = -prices[0];
            }
        }

        // 状态转移
        for (int i = 1; i < n; i++) {
            // j = 0（第一次买）
            dp[0][i] = max(dp[0][i - 1], -prices[i]);

            for (int j = 1; j < 2 * k; j++) {
                if (j % 2 == 1) {
                    // 不持有（卖）
                    dp[j][i] = max(dp[j][i - 1], dp[j - 1][i - 1] + prices[i]);
                } else {
                    // 持有（买）
                    dp[j][i] = max(dp[j][i - 1], dp[j - 1][i - 1] - prices[i]);
                }
            }
        }

        return dp[2 * k - 1][n - 1];
    }
};