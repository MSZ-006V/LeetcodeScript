/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<int, int> ht;
        int target_s_c = 0;
        for(auto c : s){
            ht[c - 'a']++;
        }
        for(auto e : ht){
            if(e.second >= k) target_s_c++;
        }
        int minimum_len = 

        return 0;
    }
};
// @lc code=end

