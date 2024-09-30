#
# @lc app=leetcode.cn id=279 lang=python
#
# [279] 完全平方数
#

# @lc code=start
class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        # 完全平方数可以通过i * i来进行计算

        dp = [float('inf')] * (n + 1)
        dp[0] = 0

        for i in range(1, int(n ** 0.5) + 1):
            for j in range(i * i, n + 1):
                dp[j] = min(dp[j], dp[j - (i * i)] + 1)
        
        # print(dp, dp[n])

        return dp[n]
    
        # wrong answer

        # for i in range(n): # 多余了，不用遍历到n，只需要遍历到n的0.5次方即可
        #     for j in range(n + 1): # 不用从0开始遍历，这样子就会出现数组越界和资源浪费的问题
        #         # 可以从i * i开始遍历，可以保证j - (i * i)一定是>=0的
        #         if j - (i * i) >= 0: # 可去除
        #             dp[j] = min(dp[j], dp[j - (i * i)] + 1)
# @lc code=end

