#
# @lc app=leetcode.cn id=72 lang=python
#
# [72] 编辑距离
#

# @lc code=start
class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        # 经典题目，使用动态规划很方便
        dp = [[0] * (len(word2) + 1) for _ in range(len(word1) + 1)]
        for i in range(len(word1) + 1):
            dp[i][0] = i
        for j in range(len(word2) + 1):
            dp[0][j] = j

        # 虽然是三种操作，替换，增加，删除，但是由于增加和删除是相同的操作
        # 比如ro和r，增加一个o和删去一个o，操作数一样，结果一样，所以完全可以等价
        for i in range(1, len(word1) + 1):
            for j in range(1, len(word2) + 1):
                if word1[i - 1] == word2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                    # 如果相同，什么操作都不用做
                else:
                    # dp[i - 1][j - 1]是修改(替换）操作，即只需要把这一位不同的，直接修改就可以了
                    # dp[i - 1][j] and dp[i][j - 1]是删除操作，即删除word1或者word2中不同的那一位
                    # 上面这两个操作都是需要+1操作数的
                    # 所以综合来说，使用min，然后+1就可以求出最少的操作数了
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1
                    # 注意，插入操作和删除操作实际上是一样的，有一样的操作数
                    # 所以可以直接略去插入操作
                    # 只考虑替换和删除操作
        
        return dp[len(word1)][len(word2)]
# @lc code=end

