/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int n) {
        // 先判断是不是2的幂
        // 4的幂的二进制形式的话，只会有一个1，在最高位，而且1的位置全部都是偶数位
        // 构造一个mask用来和n做或运算，即10101010101010101010101010101010
        // 这个数偶数位全部是1，奇数位是1，与4的幂做或运算后，肯定为0，所以用来判断
        return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
    }
};
// @lc code=end

