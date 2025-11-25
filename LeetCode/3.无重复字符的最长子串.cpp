/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_set<char> letters;
        for(int left = 0, right = 0; right < s.size(); ++right){
            char c = s[right];

            while(letters.find(c) != letters.end()){
                letters.erase(s[left]);
                left++;
            }
            letters.insert(c);
            res = max(res, right - left + 1);
        }

        return res;
    }
};
// @lc code=end

