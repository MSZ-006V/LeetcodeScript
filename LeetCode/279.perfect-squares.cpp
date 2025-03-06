/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        // 背包容量是n，物品是从1到100
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        // 相当于求组合数，顺序不同视为相同方案
        for(int i = 1; i * i < n + 1; ++i){
            for(int j = i * i; j < n + 1; ++j){
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }

        }

        return dp[n];
    }
};
// @lc code=end

