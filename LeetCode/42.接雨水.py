#
# @lc app=leetcode.cn id=42 lang=python
#
# [42] 接雨水
#

# @lc code=start
class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        stack = []
        answer = 0
        # 这个方法相当于横着计算，可以试试[5,2,1,0,4]这个数组
        # 前5,2,1,0都接不了水，一直到4才能接水，一条一条横着计算
        stack.append(0)
        for i in range(1, len(height)):
            if height[i] <= height[stack[-1]]:
                stack.append(i)
            else:
                while(len(stack) != 0 and height[i] > height[stack[-1]]):
                    mid = stack.pop()
                    # 重要的其实是这一步，这一步能够保证不重复计算，如果
                    # stack是空的，就不会访问stack[-1]了
                    # 同时也能保证左右两边不会重复计算

                    # 除此之外，下面这个步骤也能防止计算同样高度的
                    # 比如2,1,1,3这样的，第三个元素1计算出来的是0，就自动跳过了
                    # 最后还是只会计算2,1,3这个的面积
                    if len(stack) != 0:
                        h = min(height[stack[-1]], height[i]) - height[mid]
                        w = i - stack[-1] - 1
                        answer += h * w
                        print(answer)
                stack.append(i)

                
        
        return answer
# @lc code=end

