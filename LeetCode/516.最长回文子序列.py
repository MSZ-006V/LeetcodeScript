#
# @lc app=leetcode.cn id=516 lang=python
#
# [516] 最长回文子序列
#

# @lc code=start
class Solution(object):
    def longestPalindromeSubseq(self, s):
        """
        :type s: str
        :rtype: int
        """
        dp = [[0] * len(s) for _ in range(len(s))]
        for i in range(len(s)):
            dp[i][i] = 1
        # 单个字符也是回文串，最小是1
        result = 1

        for i in range(len(s) - 1, -1, -1):
            for j in range(i + 1, len(s)): # 要从i + 1开始
                # 因为下面会用到dp[i+1][j-1]，最后一行肯定不能遍历，默认直接从倒数第二行开始遍历
                if s[i] == s[j]:
                    dp[i][j] = dp[i + 1][j - 1] + 2 # 如果相同，在串两边同时加上2，更新
                else:
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])
                    # 如果不相同，找出单独加s[i]或s[j]的最大回文子序列长度
                if dp[i][j] > result:
                    result = dp[i][j]

        return result
# @lc code=end

