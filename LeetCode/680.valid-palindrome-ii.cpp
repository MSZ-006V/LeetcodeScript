/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string& s, int left, int right){
        while(left < right){
            if(s[left] != s[right]) return false;
            left++; right--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        // time complexity is O(n), space complexity is O(1)
        int left = 0, right = s.size() - 1;
        while(left < right){
            // 只能删除一次，只能删除一个字母
            // 所以当遇到不相等的字母的时候，分别讨论删除左边的一个字符和右边的一个字符
            // 查看删除后是否是回文串，使用||进行判断
            if(s[left] != s[right]){
                return isPalindrome(s, left, right - 1) || isPalindrome(s, left + 1, right);
            }
            left++;
            right--;
        }
        return true;
    }
};
// @lc code=end

