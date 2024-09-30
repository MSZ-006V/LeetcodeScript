#
# @lc app=leetcode.cn id=52 lang=python
#
# [52] N 皇后 II
#

# @lc code=start
class Solution(object):
    # 回溯法解决N皇后问题
    # 对于self.a，a[1]=2代表皇后位置在2行1列，以此类推，只需要使用一维数组就可以进行存储
    def __init__(self):
        self.a = [0] * 20
        self.solution_num = 0
        self.queen_num = 0

    def place(self, k, j):
        if j == 1:
            return True
        for i in range(1, j):
            if self.a[i] == k: # 判断是否同行
                return False
            if (abs(i - j) == abs(self.a[i] - k)): # 判断是否对角线
                return False
        return True
    
    def find(self, j):
        if j == self.queen_num + 1:
            print(self.a[:])
            self.solution_num += 1
        else:
            for k in range(1, self.queen_num + 1):
                if self.place(k, j):
                    self.a[j] = k
                    self.find(j + 1) # 递归的进行查找，每次找下一个皇后的位置
                    # 直接增加到新的一列就可以

    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
        # k是行, j是列
        self.queen_num = n
        self.find(1)
        # print("num is", self.solution_num)
        return self.solution_num
# @lc code=end

