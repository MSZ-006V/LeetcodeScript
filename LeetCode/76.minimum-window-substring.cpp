/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start

// 普通版本，需要多一个is_coverd的判断函数，基本思路还是一致
// class Solution {
// public:
//     bool is_coverd(int ht_s[], int ht_t[]){
//         for(int i = 'A'; i <= 'Z'; ++i){
//             if(ht_s[i] < ht_t[i]) return false;
//         }

//         for(int i = 'a'; i <= 'z'; ++i){
//             if(ht_s[i] < ht_t[i]) return false;
//         }

//         return true;
//     }
//     string minWindow(string s, string t) {
//         int ht_t[128]{};
//         int ht_s[128]{};
//         for(int i = 0; i < t.size(); ++i){
//             ht_t[t[i]]++;
//         }
//         int ans_left = -1, ans_right = s.size();
//         int left = 0;
//         for(int right = 0; right < s.size(); ++right){
//             ht_s[s[right]]++;
//             while(is_coverd(ht_s, ht_t)){
//                 if(right - left < ans_right - ans_left){
//                     ans_left = left;
//                     ans_right = right;
//                 }
//                 ht_s[s[left]]--;
//                 left++;
//             }
//         }
//         return ans_left == -1?"":s.substr(ans_left, ans_right - ans_left + 1);
//     }
// };
class Solution {
public:
    string minWindow(string s, string t) {
        // time complexity is O(m + n), space complexity is O(1)
        // 优化版本
        int ans_l = -1, ans_r = s.size(); // 设置这个的目的主要是如果最后找不到，那么ans_l仍然会是-1，用在最后进行判断
        int ht_t[128]{};
        int num_ctypes = 0; // 使用这个变量来记录此时的窗口中，t中字符种类缺少的个数
        for(char c : t){
            if(ht_t[c] == 0) num_ctypes++;
            ht_t[c]++;
        } 
        int left = 0;
        for(int right = 0; right < s.size(); ++right){
            ht_t[s[right]]--;
            // 如果是0，表示当前窗口中多包含了t的一种字符（比如A，B），就把num_ctypes减一
            // 如果是不相关的字符，那么在原本的ht_t中也是0，减1后就变成负数了，也不会有任何影响
            if(ht_t[s[right]] == 0) num_ctypes--; 
            while(num_ctypes == 0){ // 表示当前窗口区间已经包含了t中的所有字符种类（包括出现次数等等）
                if(right - left < ans_r - ans_l){ // 如果区间更短就记录
                    ans_r = right;
                    ans_l = left;
                }
                if(ht_t[s[left]] == 0) num_ctypes++; // 如果此时出去的s[left]这个字符是t中包含的，那么此举就会造成窗口不再包含t中所有的字符（也不满足出现次数），所以把num_ctypes加一
                ht_t[s[left]]++; // 窗口向右移动，要先判断，再移动，免得错误
                left++;
            }
        }

        return ans_l == -1?"":s.substr(ans_l, ans_r - ans_l + 1); // 如果找到就返回子字符串，没找到返回空
    }
};
// @lc code=end

