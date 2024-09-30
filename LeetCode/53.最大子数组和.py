#
# @lc app=leetcode.cn id=53 lang=python
#
# [53] 最大子数组和
#

# @lc code=start
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # dp[i]表示从0-i的最大子数组和
        dp = [0] * len(nums)
        dp[0] = nums[0]
        
        # 对每一个元素nums[i], 有两种选择
        # 和前一个dp[i - 1]相加构成子数组和，或者是从自身作子数组的第一位
        for i in range(1, len(nums)):
            dp[i] = max(dp[i - 1] + nums[i], nums[i])
        
        return max(dp)
# @lc code=end

