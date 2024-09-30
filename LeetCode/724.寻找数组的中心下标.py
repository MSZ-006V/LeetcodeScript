#
# @lc app=leetcode.cn id=724 lang=python
#
# [724] 寻找数组的中心下标
#

# @lc code=start
class Solution(object):
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sum_nums = sum(nums)
        left_sum = 0
        right_sum = sum_nums
        for i in range(len(nums)):
            right_sum -= nums[i]
            if left_sum == right_sum:
                return i
            left_sum += nums[i]
        return -1
# @lc code=end

