#
# @lc app=leetcode.cn id=714 lang=python
#
# [714] 买卖股票的最佳时机含手续费
#

# @lc code=start
class Solution(object):
    def maxProfit(self, prices, fee):
        """
        :type prices: List[int]
        :type fee: int
        :rtype: int
        """

        dp = [[0, 0] for _ in range(len(prices))]
        dp[0][0] = -prices[0] # 持有股票
        dp[0][1] = 0 # 不持有股票

        for i in range(1, len(prices)):
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i])
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee)
        # 相比基本的股票买卖问题只是多了一个手续费而已
        return dp[len(prices) - 1][1]
# @lc code=end

