#
# @lc app=leetcode.cn id=674 lang=python
#
# [674] 最长连续递增序列
#

# @lc code=start
class Solution(object):
    def findLengthOfLCIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        # 30s秒杀，太简单了
        # 因为是连续的递增序列，所以只要和上一位进行比较就好了

        dp = [1] * len(nums)
        # 初始化全部为1，因为每一个单独的元素都是一个子序列
        # 所以最低的递增连续子序列长度都是1

        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                dp[i] = dp[i - 1] + 1

        # print(dp)

        return max(dp)

# @lc code=end

