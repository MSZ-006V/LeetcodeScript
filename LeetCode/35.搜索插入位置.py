#
# @lc app=leetcode.cn id=35 lang=python
#
# [35] 搜索插入位置
#

# @lc code=start
class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        # 对于插入位置是有要求的
        # 如果数组有数与target相等，那么就插入那个数的下标就可以
        # 而且这道题是无重复元素的数组，所以直接插入那个数的下表就可以
        # 第二种情况，没有元素相等，就插入第一个比它大的数的位置即可
        # 上面这两种情况对应了两种return值
        # 分别是return mid and return right + 1
        def binary_search(nums, target):
            left = 0
            right = len(nums) - 1
            insert_index = 0
            while left <= right:
                mid = left + ((right - left) // 2)
                if nums[mid] > target:
                    right = mid - 1
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    return mid
            return right + 1
        index = binary_search(nums, target)
        # print(index)
        return index
# @lc code=end

