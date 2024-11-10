#
# @lc app=leetcode.cn id=121 lang=python
#
# [121] 买卖股票的最佳时机
#

# @lc code=start
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """

        # 贪心
        # profit = 0
        # for i in range(1, len(prices)):
        #     low = min(prices[:i])
        #     profit = max(profit, prices[i] - low)
        # print(profit)

        # 动态规划
        # dp[i][0]代表在第i天持有股票的最大收益
        # dp[i][1]代表在第i天不持有股票的最大收益
        dp = [[0, 0] for _ in range(len(prices))]
        dp[0][0] = -prices[0] # 持有股票就是买了
        dp[0][1] = 0

        # print(dp)

        for i in range(1, len(prices)):
            # 对于状态0，情况1是保持和i-1天一样，依然持有，或者是前面i-1天都没有买入，在第i天买入，所以最大收益是-prices[i]
            dp[i][0] = max(dp[i - 1][0], -prices[i])
            # 对于状态1，情况1是保持和i-1天一样，依然不持有，或者是前面i-1天买入股票，在第i天卖出了，所以最大收益是dp[i - 1][0] + prices[i]
            # 注意是dp[i - 1][0] + prices[i], 表示i-1天前买入股票的最大收益加上卖出，不要写错了
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i])

        # print(dp)
        return dp[len(prices) - 1][1] 


# @lc code=end

