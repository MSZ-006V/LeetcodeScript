#
# @lc app=leetcode.cn id=649 lang=python
#
# [649] Dota2 参议院
#

# @lc code=start
class Solution(object):
    def predictPartyVictory(self, senate):
        """
        :type senate: str
        :rtype: str
        """
        senate = list(senate)
        # R = true表示本轮循环结束后，字符串里依然有R。D同理
        R = True
        D = True
        # 当flag大于0时，R在D前出现，R可以消灭D。当flag小于0时，D在R前出现，D可以消灭R
        flag = 0

        # 一旦R或者D为false，就结束循环，说明本轮结束后只剩下R或者D了
        while R and D:
            R = False
            D = False
            for i in range(len(senate)):
                if senate[i] == 'R':
                    if flag < 0:
                        senate[i] = '0' # 消灭R, 此时R为False
                    else:
                        R = True
                    flag += 1
                if senate[i] == 'D':
                    if flag > 0:
                        senate[i] = '0' # 消灭D，此时D也为False
                    else:
                        D = True
                    flag -= 1
        
        # 当循环结束后，R和D只会有一个True
        if R:
            return 'Radiant'
        else:
            return 'Dire'
# @lc code=end

