#
# @lc app=leetcode.cn id=34 lang=python
#
# [34] 在排序数组中查找元素的第一个和最后一个位置
#

# @lc code=start
class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # 这道题没有搞懂，为什么这样子写就可以找到左边界和右边界
        def getRightBorder(nums, target):
            left, right = 0, len(nums)-1
            rightBoder = -2 # 记录一下rightBorder没有被赋值的情况
            while left <= right:
                middle = left + (right-left) // 2
                if nums[middle] > target:
                    right = middle - 1
                else: # 寻找右边界，nums[middle] == target的时候更新left
                    left = middle + 1 # 包含了<= 的情况
                    rightBoder = left
    
            return rightBoder
        
        def getLeftBorder(nums, target):
            left, right = 0, len(nums)-1 
            leftBoder = -2 # 记录一下leftBorder没有被赋值的情况
            while left <= right:
                middle = left + (right-left) // 2
                if nums[middle] >= target: #  寻找左边界，nums[middle] == target的时候更新right
                    right = middle - 1
                    leftBoder = right
                else:
                    left = middle + 1

            return leftBoder
        
        leftBoder = getLeftBorder(nums, target)
        rightBoder = getRightBorder(nums, target)
        # print(leftBoder, rightBoder)
        # 情况一
        if leftBoder == -2 or rightBoder == -2: return [-1, -1]
        # 情况三
        # 对于测试用例，上面返回的是[2, 5]，所以返回值是[3, 4]
        if rightBoder -leftBoder >1: return [leftBoder + 1, rightBoder - 1]
        # 情况二
        return [-1, -1]
    
    

            
# @lc code=end

