#
# @lc app=leetcode.cn id=84 lang=python
#
# [84] 柱状图中最大的矩形
#

# @lc code=start
class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        result = 0
        stack = []
        heights.insert(0, 0)
        heights.append(0)
        stack.append(0)
        # 对比42接雨水，这道题的单调栈是栈底到栈尾是从小到大的
        for i in range(1, len(heights)):
            if heights[i] >= heights[stack[-1]]:
                stack.append(i)
            else:
                # 其实基本做法和42是一样的
                # 都是先弹出一个作为底，即mid，然后以栈顶元素和即将入栈的元素作为两条边
                # 然后进行计算
                # 其实有点不太明白，为什么这样就能计算出最大的
                while(len(stack) != 0 and heights[i] < heights[stack[-1]]):
                    mid = stack.pop()
                    if len(stack) != 0:
                        right = i
                        left = stack[-1]
                        width = right - left - 1
                        high = heights[mid]
                        result = max(result, width * high)
                stack.append(i)
        # 这道题的原理如下
        # 对于heights数组中的每一个元素，比如第2个元素，我们可以求出以第二个元素为高度的
        # 最大矩形，这个矩形的高度是2，低的大小就是以第二个元素往两边能够延伸的最大距离
        # 所以，如果想要求出最大的矩形面积，就针对heights数组中每一个元素，在遍历时
        # 求出以那个元素作为高的最大矩形面积，然后比较即可得到最大的矩形面积
        # 所以一定要遍历一遍数组
        # 所以，对于以第i个元素，高为heights[i]的最大矩形，我们要找到从i开始，往左和往右
        # 能够延伸的最大距离，也就是找到第一个比heights[i]小的元素
        # 这种类型的题目都是单调栈的经典题目
        # 即找到某个元素往右的第一个比它大或者小的元素
        # 这种场景都是单调栈的应用场景
        # 接雨水同理
        return result
# @lc code=end

