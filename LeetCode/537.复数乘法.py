#
# @lc app=leetcode.cn id=537 lang=python
#
# [537] 复数乘法
#

# @lc code=start
import re
class Solution(object):
    def complexNumberMultiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        matches = re.findall(r'[-+]?\d+',num1)
        real1, imag1 = map(int, matches)
        matches = re.findall(r'[-+]?\d+',num2)
        real2, imag2 = map(int, matches)

        oreal = (real1 * real2) - (imag1 * imag2)
        oimag = (real1 * imag2) + (real2 * imag1)

        output = str(oreal) + '+' + str(oimag) + 'i'
        return output
# @lc code=end

