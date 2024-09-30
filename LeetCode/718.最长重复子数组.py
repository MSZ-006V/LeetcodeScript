#
# @lc app=leetcode.cn id=718 lang=python
#
# [718] 最长重复子数组
#

# @lc code=start
class Solution(object):
    def findLength(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """

        dp = [[0] * (len(nums2) + 1) for _ in range(len(nums1) + 1)]
        result = 0

        # 注意i和j都是从1开始，比较i-1和j-1的字母是否相等
        # 核心递推公式就是
        # dp[i][j] = dp[i - 1][j - 1] + 1
        for i in range(1, len(nums1) + 1):
            for j in range(1, len(nums2) + 1):
                if nums1[i - 1] == nums2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                if dp[i][j] > result:
                    result = dp[i][j]

        # print(dp)

        return result
# @lc code=end

