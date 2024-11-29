#
# @lc app=leetcode.cn id=1143 lang=python
#
# [1143] 最长公共子序列
#

# @lc code=start
class Solution(object):
    def longestCommonSubsequence(self, text1, text2):
        """
        :type text1: str
        :type text2: str
        :rtype: int
        """
        dp = [[0] * (len(text2) + 1) for _ in range(len(text1) + 1)]
        result = 0
        
        # 子数组是要连续的，子序列可以不是连续的
        # 和718的区别就是，子序列可以不是连续的，比如abcde只用ace也是一个子序列
        # 所以，要多一个else的操作，可以这么理解
        # 序列abc和ac的最长公共子序列是2
        # 序列abc和ace的最长公共子序列也是2
        for i in range(1, len(text1) + 1):
            for j in range(1, len(text2) + 1):
                if text1[i - 1] == text2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
                    
                if dp[i][j] > result:
                    result = dp[i][j]

        # print(dp)

        return result

# @lc code=end

