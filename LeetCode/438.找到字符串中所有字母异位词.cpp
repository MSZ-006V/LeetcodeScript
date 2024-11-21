/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // 时间复杂度是O(n), space complexity is O(1)
        int length = p.size();

        if(s.size() < length){
            return {};
        }
        vector<int> result;
        string ht_p = "0000000000000000000000000"; // 用字符串来当哈希表
        string ht_s = "0000000000000000000000000";
        for(int i = 0; i < length; ++i){
            ht_p[p[i] - 'a']++;
        }
        
        for(int i = 0; i < length; ++i){
            ht_s[s[i] - 'a']++;
        }
        // if(ht_s == ht_p) result.push_back(0);
        //cout << ht_s << ' ' << ht_p;


        for(int i = length; i < s.size(); ++i){
            ht_s[s[i - length] - 'a']--;
            ht_s[s[i] - 'a']++;
            if(ht_s == ht_p){
                result.push_back(i - length + 1);
            }
        }

        return result;

        // 也可以用下面这种方法，定长滑动窗口
        int length = p.size();

        if(s.size() < length){
            return {};
        }
        vector<int> result;
        string ht_p = "0000000000000000000000000"; // 用字符串来当哈希表
        string ht_s = "0000000000000000000000000";
        for(int i = 0; i < length; ++i){
            ht_p[p[i] - 'a']++;
        }

        for(int right = 0; right < s.size(); ++right){
            ht_s[s[right] - 'a']++;
            int left = right - length + 1;
            if(left < 0) continue;
            if(ht_p == ht_s){
                result.push_back(left);
            }
            ht_s[s[left] - 'a']--;
        }
        return result;
    }
};
// @lc code=end

