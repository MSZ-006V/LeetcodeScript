#
# @lc app=leetcode.cn id=925 lang=python
#
# [925] 长按键入
#

# @lc code=start
class Solution(object):
    def isLongPressedName(self, name, typed):
        """
        :type name: str
        :type typed: str
        :rtype: bool
        """
        i = j = 0
        while(i<len(name) and j<len(typed)):
        # If the current letter matches, move as far as possible
            if typed[j]==name[i]:
                while j+1<len(typed) and typed[j]==typed[j+1]:
                    j+=1
                    # special case when there are consecutive repeating letters
                    if i+1<len(name) and name[i]==name[i+1]:
                        i+=1
                else:
                    j+=1
                    i+=1
            else:
                return False
        return i == len(name) and j==len(typed)

        
# @lc code=end

