/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // time complexity is O(n), space compleixty is O(1)
        // 简单题，可以利用字符串作为哈希表，同时滑动窗口公式化做题
        int left = 0;
        int length = s1.size();
        string ht_s1 = "00000000000000000000000000";
        string ht_s2 = "00000000000000000000000000";
        for(auto c : s1){
            ht_s1[c - 'a']++;
        }

        for(int right = 0; right < s2.size(); ++right){
            ht_s2[s2[right] - 'a']++;
            if(right - left + 1 > length){
                ht_s2[s2[left] - 'a']--;
                left++;
            }
            if(ht_s2 == ht_s1) return true;
        }

        return false;
    }
};
// @lc code=end

