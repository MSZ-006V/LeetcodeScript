/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 136只需要用异或操作，异或操作可以看为模2加法
        // 而这道题需要用到模3加法
        int a = 0, b = 0;
        for(auto num : nums){
            b = (b ^ num) & ~a;
            a = (a ^ num) & ~b;
        }
        return b;
    }
};
// @lc code=end

