#
# @lc app=leetcode.cn id=1221 lang=python
#
# [1221] 分割平衡字符串
#

# @lc code=start
class Solution(object):
    def balancedStringSplit(self, s):
        """
        :type s: str
        :rtype: int
        """
        R_num = 0
        L_num = 0
        num = 0
        for i in range(len(s)):
            if s[i] == 'R':
                R_num += 1
            else:
                L_num += 1
            
            if R_num == L_num:
                num += 1
                R_num, L_num = 0, 0
        return num
# @lc code=end

