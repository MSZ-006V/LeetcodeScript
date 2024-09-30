#
# @lc app=leetcode.cn id=1002 lang=python
#
# [1002] 查找共用字符
#

# @lc code=start
class Solution(object):
    def commonChars(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        word_num = len(words)
        
        hash = [0] * 26
        for i in range(len(words[0])):
            hash[ord(words[0][i]) - ord('a')] += 1
        
        for i in range(1, word_num):
            dict = [0] * 26 # 每次对新的word进行计算的时候，必须要清空
            for j in range(len(words[i])):
                dict[ord(words[i][j]) - ord('a')] += 1
            
            for j in range(26):
                hash[j] = min(hash[j], dict[j]) 
                # 利用min，取最小的，保证那种不是在所有字符串中都出现的字符
                # 在经过这一步后，在hash中的值一定会变成0
                # 因为肯定在某个word中没有出现，是0
                # 使用min保证为0
        
        # print(hash)
        result = []
        # 根据hash数组来生成结果即可
        for i in range(26):
            for _ in range(hash[i]):
                result.append(chr(i + ord('a'))) # 转换回去
        return result
# @lc code=end

