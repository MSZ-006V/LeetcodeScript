#
# @lc app=leetcode.cn id=132 lang=python
#
# [132] 分割回文串 II
#

# @lc code=start
class Solution(object):
    def __init__(self):
        self.is_Palindromic = []
        self.path = []
        self.min_cut = 0

    def judge(self, s, start, end):
        while start < end:
            if s[start] != s[end]:
                return False
            start += 1
            end -= 1
        return True
    
    def backtracking(self, s, start_index):
        if start_index >= len(s):
            # self.result.append(len(self.path[:]))
            self.min_cut = min(self.min_cut, len(self.path))
            return
        
        if len(self.path) > self.min_cut:
            return

        for i in range(start_index, len(s)):
            if self.is_Palindromic[start_index][i]:
                self.path.append(s[start_index:(i + 1)])
                self.backtracking(s, i + 1)
                self.path.pop()

    def minCut(self, s):
        """
        :type s: str
        :rtype: int
        """

        # 一定要把是否是回文串的结果保存下来，不然每一次都要调用self.judge会很耗时
        # 保存回文串的结果是很重要的
        self.is_Palindromic = [[False] * len(s) for _ in range(len(s))]
        # 这里求回文串的方法，可以参考LeetCode第五题，照搬就是
        for i in range(len(s)-1,-1,-1):
            for j in range(i,len(s)):
                if s[i] == s[j]:
                    if j-i<=1 or self.is_Palindromic[i+1][j-1]:
                        self.is_Palindromic[i][j] = True
        # print(is_Palindromic)
        # ----------------------------------------------------------
        # 回溯法，会超时
        # self.min_cut = len(s)
        # self.backtracking(s, 0)
        # # print(self.min_cut)
        # if (self.min_cut - 1) < 0:
        #     return 0
        # else:
        #     return self.min_cut - 1
        # ----------------------------------------------------------
        # 动态规划法
        dp = [i for i in range(len(s))]
        # 初始化为每个位置上最大的分割次数

        for i in range(1, len(s)):
            # 如果0~i是回文串，那么分割0~i的最小次数自然就是0，下面也不用进行，直接continue
            if self.is_Palindromic[0][i]:
                dp[i] = 0
                continue
            # 如果0~i不是回文串，就要对0~i这个子串，从0~i进行遍历
            # j是一个分割点，j=0时，意味着分割点在0和1之间(j+1)
            # 所以，如果j+1到i是一个回文串，那么从j+1进行分割的次数就是：dp[j]+1
            # dp[j]是代表0~j最小的分割次数
            # 按照这个顺序逐个进行遍历即可
            for j in range(0, i):
                if self.is_Palindromic[j + 1][i]:
                    # 要求最小的dp[i]，肯定在min()里面要有dp[i]的，不用多想
                    dp[i] = min(dp[i], dp[j] + 1)

        # print(dp)
        return dp[len(s) - 1]
        
# @lc code=end

