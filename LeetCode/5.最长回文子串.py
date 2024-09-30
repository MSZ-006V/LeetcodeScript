#
# @lc app=leetcode.cn id=5 lang=python
#
# [5] 最长回文子串
#

# @lc code=start
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        max_len = 0
        left = 0
        right = 0
        # dp[i][j]表示区间i~j是否是回文子串，如果是就是True，不是就是False
        dp = [[False] * len(s) for _ in range(len(s))]
        # print(dp)
        # 从下往上，从左往右开始遍历
        # 实际上，下面的遍历方式，只会遍历到dp数组中的上三角部分
        # 之所以这种遍历方式，主要是因为要借助dp[i+1][j-1]的值
        # 如果s[i]==s[j], 同时i和j离的够远，那么只要看看dp[i+1][j-1]是否是回文子串
        # 就可以推导出dp[i][j]是不是了，在回文子串两边加上相同的字母，仍然是回文子串
        for i in range(len(s) - 1, -1, -1):
            for j in range(i, len(s)): # 一定 j>=i
                if s[i] == s[j]:
                    if j - i <= 1:
                        dp[i][j] = True
                    elif dp[i + 1][j - 1]:
                        dp[i][j] = True
                if dp[i][j] and j - i + 1 > max_len:
                    max_len = j - i + 1 # 更新最大长度
                    left = i # 记录两边的坐标，因为要返回子串
                    right = j
        return s[left:right + 1]
# @lc code=end

