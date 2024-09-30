#
# @lc app=leetcode.cn id=647 lang=python
#
# [647] 回文子串
#

# @lc code=start
class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        dp = [[False] * (len(s)) for _ in range(len(s))]

        result = 0

        for i in range(len(s) - 1, -1, -1):
            for j in range(i, len(s)):
                if s[i] == s[j]:
                    if j - i <= 1: # 如果序列i到j的长度小于等于1
                        result += 1
                        dp[i][j] = True
                    elif dp[i + 1][j - 1]: # 如果序列i到j的长度大于1
                        # 这里不用担心越界，因为最后一行在遍历的时候，只能遍历i=j的这种情况
                        # 所以这个elif绝对不会被访问到，不会越界
                        result += 1
                        dp[i][j] = True
        
        return result
# @lc code=end

