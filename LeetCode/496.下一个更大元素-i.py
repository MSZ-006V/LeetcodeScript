#
# @lc app=leetcode.cn id=496 lang=python
#
# [496] 下一个更大元素 I
#

# @lc code=start
class Solution(object):
    def nextGreaterElement(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        answer = [-1] * len(nums2)
        stack = []
        stack.append(0)
        # 这道题思路和739每日温度基本一样，先求出nums2数组的右边最大数的结果answer
        # 然后再根据nums1数组中每个元素在nums2数组的下标来访问answer数组，复制进ans数组即可
        for i in range(1, len(nums2)):
            if nums2[i] <= nums2[stack[-1]]:
                stack.append(i)
            else:
                while(len(stack) != 0 and nums2[i] > nums2[stack[-1]]):
                    answer[stack[-1]] = nums2[i]
                    stack.pop()
                stack.append(i)
        # print(answer)
        ans = []
        for i in range(len(nums1)):
            index = nums2.index(nums1[i])
            ans.append(answer[index])
        
        return ans

# @lc code=end

