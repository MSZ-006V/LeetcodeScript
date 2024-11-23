#
# @lc app=leetcode.cn id=300 lang=python
#
# [300] 最长递增子序列
#

# @lc code=start
class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 设dp[i]为目前0~i的最长递增子序列长度
        dp = [1] * len(nums)

        # 当遍历到i个元素的时候，对0~i-1的元素进行遍历，比较出最大的长度
        # 然后+1，即j从051
        for i in range(1, len(nums)):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
        
        # print(dp)

        return max(dp)
# @lc code=end

