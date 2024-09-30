#
# @lc app=leetcode.cn id=739 lang=python
#
# [739] 每日温度
#

# @lc code=start
class Solution(object):
    def dailyTemperatures(self, temperatures):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """
        # 单调栈经典题目
        # 当通常是一维数组，要寻找任一个元素的右边或者左边第一个比自己大或者小的
        # 元素的位置，此时我们就要想到可以用单调栈了，时间复杂度是O(n)
        # 暴力解法，超时
        # answer = []
        # flag = False
        # for i in range(len(temperatures)):
        #     flag = False
        #     for j in range(i, len(temperatures)):
        #         if temperatures[j] > temperatures[i]:
        #             answer.append(j - i)
        #             flag = True
        #             break
        #     if flag == False:
        #         answer.append(0)
        
        # return answer
        # 单调栈，如果求右边更大的数，从栈顶到栈底是递增序列
        # 如果求右边更小的数，从栈顶到栈底是递减序列
        stack = []
        answer = [0] * len(temperatures)
        stack.append(0)
        for i in range(1, len(temperatures)):
            if temperatures[i] <= temperatures[stack[-1]]:
                stack.append(i)
            else:
                # 注意，栈不为空的条件要写在前面，不然先判断大小的话，栈空会造成数组越界的
                while(len(stack) != 0 and temperatures[i] > temperatures[stack[-1]]):
                    answer[stack[-1]] = i - stack[-1]
                    stack.pop()
                stack.append(i)
        
        return answer

# @lc code=end

