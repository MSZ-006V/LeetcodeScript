#
# @lc app=leetcode.cn id=474 lang=python
#
# [474] 一和零
#

# @lc code=start
class Solution(object):
    def findMaxForm(self, strs, m, n):
        """
        :type strs: List[str]
        :type m: int zero
        :type n: int one
        :rtype: int
        """
        dp = [[0] * (m + 1) for _ in range(n + 1)]
        # print(dp)
        for str in strs:
            Onenum = str.count('1')
            Zeronum = len(str) - Onenum
            
            for i in range(n, Onenum - 1, -1):
                for j in range(m, Zeronum - 1, -1):
                    dp[i][j] = max(dp[i][j], dp[i - Onenum][j - Zeronum] + 1)
        
        return dp[n][m]

# @lc code=end

