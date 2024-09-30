#
# @lc app=leetcode.cn id=322 lang=python
#
# [322] 零钱兑换
#

# @lc code=start
class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        dp = [float('inf')] * (amount + 1)
        dp[0] = 0

        for i in range(len(coins)):
            for j in range(coins[i], amount + 1):
                dp[j] = min(dp[j], dp[j - coins[i]] + 1)
                # 这题是求零钱兑换的最小个数，所以使用min方法
                # dp[j - coins[i]] + 1的意思是加一个钱币
                
        
        if dp[amount] == float('inf'):
            return -1
        return dp[amount]


# @lc code=end

