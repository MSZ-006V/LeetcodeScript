#
# @lc app=leetcode.cn id=123 lang=python
#
# [123] 买卖股票的最佳时机 III
#

# @lc code=start
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        
        # 对于dp[0], [0]表示第一次持股，[1]表示第一次不持股
        # [2]表示第二次持股，[3]表示第二次不持股
        dp = [[0, 0, 0, 0] for _ in range(len(prices))]
        dp[0][0] = 0 - prices[0]
        dp[0][1] = 0 
        dp[0][2] = 0 - prices[0]
        dp[0][3] = 0 

        for i in range(1, len(prices)):
            dp[i][0] = max(dp[i - 1][0], -prices[i])
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i])
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i])
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + prices[i])
            # 为什么这里都是递增的呢，因为已经规定了是第几次持股或者不持股的了
            # 对比与前面股票买卖i和ii，前面两道题是没有规定第几次的，所以并不知道这是第几次买卖
            # 因为不知道是第几次买卖，所以要使用之前的状态
            # 但是在这道题，因为最多就执行2次买卖，所以规定了是第几次持股
            # 所以在进行状态转移的时候，就需要递增的处理
            # 第二次持股之前一定是第一次不持股
            # 第二次不持股之前一定是第二次持股
        print(dp)

        return dp[len(prices) - 1][3]
# @lc code=end

