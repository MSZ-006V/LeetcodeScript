#
# @lc app=leetcode.cn id=941 lang=python
#
# [941] 有效的山脉数组
#

# @lc code=start
class Solution(object):
    def validMountainArray(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        if len(arr) < 3:
            return False
        peek_index = arr.index(max(arr))
        # 特殊判断，如果峰顶在最后一个或者在第一个，都不是mountain array，返回false
        if peek_index == len(arr) - 1 or peek_index == 0:
            return False
        
        # 按照定义进行遍历
        for i in range(1, len(arr)):
            if i < peek_index:
                if arr[i] <= arr[i - 1]:
                    return False
            if i > peek_index:
                if arr[i] >= arr[i - 1]:
                    return False
        
        return True
# @lc code=end

