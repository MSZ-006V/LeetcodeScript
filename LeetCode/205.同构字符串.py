#
# @lc app=leetcode.cn id=205 lang=python
#
# [205] 同构字符串
#

# @lc code=start
class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        length = len(s)
        dict_s = {}
        dict_t = {}
        # 如果存在一个字符映射到多个字符，返回False
        for i in range(length): # 检查映射
            if dict_s.get(s[i]) is not None:
                if t[i] != dict_s[s[i]]:
                    return False
            else:
                dict_s[s[i]] = dict_s.get(s[i],t[i])
        # 逆检查一遍
        for i in range(length): # 检查映射
            if dict_t.get(t[i]) is not None:
                if s[i] != dict_t[t[i]]:
                    return False
            else:
                dict_t[t[i]] = dict_t.get(t[i],s[i])
        return True
# @lc code=end
