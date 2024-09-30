#
# @lc app=leetcode.cn id=198 lang=python
#
# [198] 打家劫舍
#

# @lc code=start
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        if len(nums) == 1:
            return nums[0]

        dp = [0] * len(nums)
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1]) # 初始化第一次写写错了
        # 应该选房屋0和1偷盗价值最大的

        # dp[i] 表示对当前房屋有两种操作，偷或者不偷
        # 偷的最大收益是dp[i - 2] + nums[i]
        # 不偷则代表上一座房屋偷了，所以最大收益是dp[i - 1]
        for i in range(2, len(nums)):
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
        
        return max(dp)
# @lc code=end

