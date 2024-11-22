/*
 * @lc app=leetcode id=1297 lang=cpp
 *
 * [1297] Maximum Number of Occurrences of a Substring
 */

// @lc code=start
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size();
        unordered_map<string, int> subs;
        int ans = 0;
        // for(int left = 0; left < n; ++left){
        //     unordered_set<char> letters;
        //     string cur;
        //     for(int right = left; right < min(n, left + maxSize); ++right){
        //         letters.insert(s[right]);
        //         if(letters.size() > maxLetters) break;
        //         cur = cur + s[right];
        //         if(right - left + 1 >= minSize){
        //             subs[cur]++;
        //             ans = max(ans, subs[cur]);
        //         }
        //     }
        // }

        // 灵神的滑动窗口思路，而且是优化版本，运用ctypes来统计字符数量
        // 只需要两个map就可以，时间复杂度是O(N), 空间复杂度是O(1)
        unordered_map<char, int> letters;
        int left = 0;
        int ctypes = 0;
        for(int right = 0; right < n; ++right){
            letters[s[right]]++;
            if(letters[s[right]] == 1) ctypes++;
            while(ctypes > maxLetters || right - left + 1 > minSize){
                letters[s[left]]--;
                if(letters[s[left]] == 0) ctypes--;
                left++;
            }
            if(ctypes <= maxLetters){
                if(right - left + 1 == minSize){
                    string cur = s.substr(left, minSize);
                    subs[cur]++;
                    ans = max(ans, subs[cur]);
                }
            }
        }

        return ans;
    }
};
// @lc code=end

