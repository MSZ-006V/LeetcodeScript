#
# @lc app=leetcode.cn id=213 lang=python
#
# [213] 打家劫舍 II
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
        
        n = len(nums)

        value1 = self.robfunc(nums[:n - 1])
        value2 = self.robfunc(nums[1:])
        # 考虑没有头房屋和尾房屋的情况，进行对比，返回最大的就可以了

        # print(value1, value2)
        return max(value1, value2)
    
    def robfunc(self, nums):
        if len(nums) == 1:
            return nums[0]

        dp = [0] * len(nums)
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1]) # 初始化第一次写写错了
        # 应该选房屋0和1偷盗价值最大的

        for i in range(2, len(nums)):
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])

        
        return max(dp)
# @lc code=end

