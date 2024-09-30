#
# @lc app=leetcode.cn id=922 lang=python
#
# [922] 按奇偶排序数组 II
#

# @lc code=start
class Solution(object):
    def sortArrayByParityII(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        evenindex = 0
        oddindex = 1
        while evenindex <= len(nums) - 1:
            if nums[evenindex] % 2 == 1:
                while oddindex <= len(nums) - 1:
                    if nums[oddindex] % 2 == 0:
                        break
                    oddindex += 2
                nums[evenindex], nums[oddindex] = nums[oddindex], nums[evenindex]
            evenindex += 2

        # print(nums)
        return nums
# @lc code=end

