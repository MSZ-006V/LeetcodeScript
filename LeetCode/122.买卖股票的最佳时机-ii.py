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

        # 动态规划，和121的区别就是可以无限次的买卖，只求最大利润，而123限制只可以买卖2次，121只可以买卖1次
        dp = [[0, 0] for _ in range(len(prices))]
        dp[0][0] = -prices[0]
        dp[0][1] = 0

        # dp[i][0]代表持有股票
        # dp[i][1]代表不持有股票

        for i in range(1, len(prices)):
            # dp[i][0]是选一个最好的时间买进股票，而dp[i][1]就是找一个最合适的时间卖出股票
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i])
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i])
        
        print(dp)

        return dp[len(prices) - 1][1]
# @lc code=end

