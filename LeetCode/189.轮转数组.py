#
# @lc app=leetcode.cn id=189 lang=python
#
# [189] 轮转数组
#

# @lc code=start
class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        # 轮转数组的一种方法，向右旋转
        # 翻转整个数组
        # 翻转从0到k-1的数组
        # 翻转从k到末尾的数组

        # 如果是向左旋转
        # 翻转区间为前k-1的子串
        # 翻转区间为k到末尾的子串
        # 翻转整个字符串
        
        def reverse(i, j):
            while i < j:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
                j -= 1

        n = len(nums)
        k = k % n
        reverse(0, n - 1)
        reverse(0, k - 1)
        reverse(k, n - 1)



# @lc code=end

