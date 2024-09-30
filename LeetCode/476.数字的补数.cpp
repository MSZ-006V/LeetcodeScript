/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 */

// @lc code=start
class Solution {
public:
    int findComplement(int num) {
        unsigned p = 1;
        while(p < num){
            p <<= 1;
            p++;
        }
        return num ^ p;
    }
};
// @lc code=end

