#
# @lc app=leetcode.cn id=96 lang=python
#
# [96] 不同的二叉搜索树
#

# @lc code=start
class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1:
            return 1
        if n == 2:
            return 2
        dp = [0] * (n + 1)
        dp[0] = 1
        dp[1] = 1
        dp[2] = 2

        for i in range(3, n + 1):
            for j in range(i):
                dp[i] += dp[j] * dp[i - j - 1]

        print(dp)
        return dp[n]
# @lc code=end

