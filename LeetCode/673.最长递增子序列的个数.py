#
# @lc app=leetcode.cn id=673 lang=python
#
# [673] 最长递增子序列的个数
#

# @lc code=start
class Solution(object):
    def findNumberOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # dp[i]表示从0~i序列中递增子序列的最大长度
        dp = [1] * len(nums)
        # count[i]表示从0~i序列中最大递增子序列长度的最大个数
        count = [1] * len(nums)

        for i in range(1, len(nums)):
            for j in range(i):
                # 以i结尾的序列，j从0到i-1进行遍历
                # 如果找到一个nums[j]小于nums[i]的，那么就会满足nums[j], nums[i]是一个递增的子序列
                # 所以，dp[i]的值就是dp[j] + 1
                # 同时也可以推出count[i]的值就是count[j]的值，直接复制过来就可以
                # 因为j是不断遍历的，所以遇到更大的dp[j]+1且满足条件，肯定要更新dp[i]的
                if nums[i] > nums[j]:
                    if dp[j] + 1 > dp[i]:
                        dp[i] = dp[j] + 1
                        count[i] = count[j]
                    # 如果没有遇到更大的dp[j]+1，而且还碰到dp[j]+1==dp[i]的话
                    # 就说明不止存在一个当前最大长度的递增子序列，由于题目要求所有递增子序列的个数
                    # 自然就需要对count[i]=count[i]+count[j],记录所有的符合要求的子序列个数
                    elif dp[j] + 1 == dp[i]:
                        count[i] += count[j]
        
        print(dp, count)
        max_len = max(dp) # 找到最大长度
        result = 0
        for i in range(len(nums)):
            if dp[i] == max_len: # 可能不止存在一个dp[i]是最大长度，这些dp[i]对应的count[i]要全部都加上
                result += count[i]
        # 可能的dp和count数组如下
        # dp = 1,2,3,4,3,2,4,2,2,1
        # count = 2,3,1,1,2,3,2,1,2,1
        # 最大长度是4，所以4对应的序列个数是1+2=3
        # 因为序列结尾不一定是相同的，可能前面有几条，后面有几条，很正常，需要对所有的都进行统计
        return result
# @lc code=end

