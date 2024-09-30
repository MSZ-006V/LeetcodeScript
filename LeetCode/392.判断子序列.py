#
# @lc app=leetcode.cn id=392 lang=python
#
# [392] 判断子序列
#

# @lc code=start
class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        dp = [[0] * (len(t) + 1) for _ in range(len(s) + 1)]
        result = 0

        for i in range(1, len(s) + 1):
            for j in range(1, len(t) + 1):
                if s[i - 1] == t[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = dp[i][j - 1]
                if dp[i][j] > result:
                    result = dp[i][j]

        # print(dp)
        if result == len(s):
            return True
        else:
            return False

# @lc code=end

