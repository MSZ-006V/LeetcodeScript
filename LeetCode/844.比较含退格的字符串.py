#
# @lc app=leetcode.cn id=844 lang=python
#
# [844] 比较含退格的字符串
#

# @lc code=start
class Solution(object):
    def backspaceCompare(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        result1 = []
        result2 = []
        for i in range(len(s)):
            if s[i] != '#':
                result1.append(s[i])
            else:
                if len(result1) != 0:
                    result1.pop()
        str1 = ''.join(result1)
        for i in range(len(t)):
            if t[i] != '#':
                result2.append(t[i])
            else:
                if len(result2) != 0:
                    result2.pop()
        str2 = ''.join(result2)
        
        return str1 == str2
# @lc code=end

