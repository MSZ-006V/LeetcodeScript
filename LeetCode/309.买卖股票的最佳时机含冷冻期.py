#
# @lc app=leetcode.cn id=309 lang=python
#
# [309] 买卖股票的最佳时机含冷冻期
#

# @lc code=start
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        # 处理特殊情况
        if len(prices) == 1:
            return 0
        if len(prices) == 2:
            if prices[0] < prices[1]:
                return prices[1] - prices[0]
            else:
                return 0
        
        # [0]代表持有，[1]代表不持有
        # 代表第i天持有或不持有股票获得的最大收益，因为是最大收益，所以使用max函数
        
        dp = [[0, 0] for _ in range(len(prices))]
        dp[0][0] = -prices[0]
        dp[0][1] = 0

        dp[1][0] = max(dp[0][0], -prices[1])
        dp[1][1] = max(dp[0][1], dp[0][0] + prices[1])

        # 与188题和普通的买卖股票唯一的区别就是状态转移方程有变化
        for i in range(2, len(prices)):
            dp[i][0] = max(dp[i - 1][0], dp[i - 2][1] - prices[i])
            # 要从前2天开始算，这里是不同的地方
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i])

        print(dp)

        return dp[len(prices) - 1][1]
# @lc code=end

