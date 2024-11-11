/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 */

// @lc code=start
class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        string result(n, 0);
        vector<int> count(26, 0);
        int m = 0;
        char m_ch;

        for(auto c : s){
            count[c - 'a']++;
            if(count[c - 'a'] > m){
                m_ch = c;
                m = count[c - 'a'];
            }
        }
        if(m > n - m + 1) return "";

        int i = 0;
        // 先填最多的，剩下的按照顺序填就好了
        for(; m--; i += 2){
            result[i] = m_ch;
        }
        count[m_ch - 'a'] = 0;

        for(int j = 0; j < 26; ++j){
            int cnt = count[j];
            while(cnt--){
                if(i >= n){ // 最多的已经填完了，假如最多的那个字母占字符串的一半以上，这个时候i就会>=n, 所以让i回归到1
                    i = 1;
                }
                result[i] = j + 'a';
                i += 2;
            }
        }

        return result;
    }
};
// @lc code=end

