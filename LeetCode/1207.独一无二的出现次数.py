#
# @lc app=leetcode.cn id=1207 lang=python
#
# [1207] 独一无二的出现次数
#

# @lc code=start
class Solution(object):
    def uniqueOccurrences(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        dict = {}
        
        for i in range(len(arr)):
            dict[arr[i]] = dict.get(arr[i], 0) + 1

        result_dict = {}

        for value in dict.values():
            result_dict[value] = result_dict.get(value, 0) + 1
            if result_dict[value] > 1:
                return False
        return True
# @lc code=end

