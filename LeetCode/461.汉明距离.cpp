/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int Count(int n){
        int count = 0;
        while(n){
            n = n & (n - 1);
            count++;
        }
        return count;
    }
    int hammingDistance(int x, int y) {
        int n = x ^ y; // 使用异或进行计算，计算结果中的1的个数就是汉明距离
        return Count(n);
    }
};
// @lc code=end

