#
# @lc app=leetcode.cn id=188 lang=python
#
# [188] 买卖股票的最佳时机 IV
#

# @lc code=start
class Solution(object):
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """

        # 123题的改进版，即可以买卖k次，123题是只可以买卖2次
        # 即在循环的地方多加一个循环即可，同时对于dp[i][0]特殊处理即可

        # j为双数表示持有，单数表示不持有
        dp = [[0] * (k * 2) for _ in range(len(prices))]
        for i in range(2 * k): # 初始化
            if i % 2 == 0: # 双数
                dp[0][i] = -prices[0]
        
        for i in range(1, len(prices)):
            dp[i][0] = max(dp[i - 1][0], -prices[i])
            for j in range(1, 2 * k):
                if j % 2 == 1:
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i])
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i])

        # print(dp)
        return dp[len(prices) - 1][(2 * k) - 1]

# @lc code=end

