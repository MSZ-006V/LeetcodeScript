#
# @lc app=leetcode.cn id=139 lang=python
#
# [139] 单词拆分
#

# @lc code=start
class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """

        dp = [False] * (len(s) + 1)
        dp[0] = True
        # 相当于wordDict是物品，每个物品都是无限的，而字符串s为背包
        # 这题相当于求排列，因为单词的顺序是必要的，如果单词的顺序颠倒，可能不能保证分割
        
        for i in range(1, len(s) + 1):
            for word in wordDict:
                if i >= len(word):
                    dp[i] = dp[i] or (dp[i - len(word)] and word == s[i - len(word):i])
        # true的条件1是，此时dp[i - len(word)]是true, 代表前面加上这个单词是可以进行分割的
        # 条件2是，单词word == s[i - len(word):i], i代表遍历到的位置，i只需要遍历一遍
        # print(dp)
        return dp[len(s)]
                 
# @lc code=end