/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for(int i = 0; i < coins.size(); ++i){ // 相当于对于每一种面额的零钱，分别的计算
            for(int j = coins[i]; j < amount + 1; ++j){ // 是顺序进行遍历的
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        if(dp[amount] == amount + 1){ // 表示没有找到正确的答案，初始化的答案没有被修改
            return -1;
        }
        return dp[amount];
    }
};
// @lc code=end

