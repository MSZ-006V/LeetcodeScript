#
# @lc app=leetcode.cn id=583 lang=python
#
# [583] 两个字符串的删除操作
#

# @lc code=start
class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        dp = [[0] * (len(word2) + 1) for _ in range(len(word1) + 1)]
        for i in range(1, len(word1) + 1):
            dp[i][0] = i
        for i in range(1, len(word2) + 1):
            dp[0][i] = i
        
        for i in range(1, len(word1) + 1):
            for j in range(1, len(word2) + 1):
                if word1[i - 1] == word2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = min(dp[i][j - 1] + 1, dp[i - 1][j] + 1)
        
        return dp[len(word1)][len(word2)]
                
# @lc code=end

