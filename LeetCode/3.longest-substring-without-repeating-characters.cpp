/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 滑动窗口，固定右边界，不断查看左边界是否符合情况
        // 每一次循环找的是以right结尾的最长无重复连续子串的长度
        int n = s.size();
        set<char> ht;
        int res = 0;
        for(int left = 0, right = 0; right < n; ++right){
            char ch = s[right];
            while(ht.find(ch) != ht.end()){
                ht.erase(s[left]);
                left++;
            }
            ht.insert(ch);
            res = max(res, right - left + 1);
        }
        return res;
    }
};
// @lc code=end

