#
# @lc app=leetcode.cn id=518 lang=python
#
# [518] 零钱兑换 II
#

# @lc code=start
class Solution(object):
    def change(self, amount, coins):
        """
        :type amount: int
        :type coins: List[int]
        :rtype: int
        """
        dp = [0] * (amount + 1)

        dp[0] = 1
        for i in range(len(coins)):
            for j in range(coins[i], amount + 1):
                dp[j] = dp[j] + dp[j - coins[i]] # 这题是求钱币的组合方式的个数，所以是
                # 使用dp[j] + dp[j - coins[i]], 可以和322进行对比
            print(dp)

        return dp[amount]
        
        
# @lc code=end

