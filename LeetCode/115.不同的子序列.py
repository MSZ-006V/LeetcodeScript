#
# @lc app=leetcode.cn id=115 lang=python
#
# [115] 不同的子序列
#

# @lc code=start
class Solution(object):
    def numDistinct(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        dp = [[0] * (len(t) + 1) for _ in range(len(s) + 1)]
        for i in range(len(s) + 1):
            dp[i][0] = 1
        
        for i in range(1, len(s) + 1): # 记得从1开始遍历
            for j in range(1, len(t) + 1):
                if s[i - 1] == t[j - 1]: # 从左上角和正上方接受信息，可以想象一下dp数组的样子
                    # dp数组的行是目标串，列是模式串
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
                else: # 教程上说，这一步类似删除操作
                    dp[i][j] = dp[i - 1][j]
        
        # print(dp)
        return dp[len(s)][len(t)]
# @lc code=end

