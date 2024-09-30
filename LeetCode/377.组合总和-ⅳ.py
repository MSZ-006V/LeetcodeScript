#
# @lc app=leetcode.cn id=377 lang=python
#
# [377] 组合总和 Ⅳ
#

# @lc code=start
class Solution(object):
    def combinationSum4(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        dp = [0] * (target + 1)
        dp[0] = 1

        for i in range(target + 1):
            for j in range(len(nums)):
                if i - nums[j] >= 0:
                    dp[i] += dp[i - nums[j]]
            print(dp)
        
        return dp[target]
# @lc code=end

