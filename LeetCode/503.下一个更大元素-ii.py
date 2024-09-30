#
# @lc app=leetcode.cn id=503 lang=python
#
# [503] 下一个更大元素 II
#

# @lc code=start
class Solution(object):
    def nextGreaterElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        stack = []
        answer = [-1] * len(nums)
        stack.append(0)
        size = len(nums)
        # 简单的方法就是把两个nums数组拼接一下
        # 高级的方法就是遍历两遍
        for i in range(1, size * 2):
            if nums[i % size] <= nums[stack[-1]]:
                stack.append(i % size)
            else:
                while(len(stack) != 0 and nums[i % size] > nums[stack[-1]]):
                    answer[stack[-1]] = nums[i % size]
                    stack.pop()
                stack.append(i % size)
        
        return answer

# @lc code=end

