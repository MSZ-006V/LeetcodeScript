#
# @lc app=leetcode.cn id=1365 lang=python
#
# [1365] 有多少小于当前数字的数字
#

# @lc code=start
class Solution(object):
    def smallerNumbersThanCurrent(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        new_nums = sorted(nums, key=lambda x:x)
        dict = {new_nums[0]:0}
        for i in range(1, len(new_nums)):
            if new_nums[i] != new_nums[i - 1]:
                dict[new_nums[i]] = dict.get(new_nums[i], 0) + i
        # print(dict)
        result = []
        for i in range(len(nums)):
            result.append(dict[nums[i]])
        return result
# @lc code=end

