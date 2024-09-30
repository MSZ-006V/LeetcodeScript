#
# @lc app=leetcode.cn id=122 lang=python
#
# [122] 买卖股票的最佳时机 II
#

# @lc code=start
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """

        # 贪心
        # profits = [prices[i + 1] - prices[i] for i in range(len(prices) - 1)]
        # profit = 0
        # for i in range(len(profits)):
        #     if profits[i] > 0:
        #         profit += profits[i]

        # return profit

        # 动态规划
        dp = [[0, 0] for _ in range(len(prices))]
        dp[0][0] = -prices[0]
        dp[0][1] = 0

        # dp[i][0]代表持有股票
        # dp[i][1]代表不持有股票

        for i in range(1, len(prices)):
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i])
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i])
        
        print(dp)

        return dp[len(prices) - 1][1]
# @lc code=end

