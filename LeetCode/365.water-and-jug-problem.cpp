/*
 * @lc app=leetcode id=365 lang=cpp
 *
 * [365] Water and Jug Problem
 */

// @lc code=start
class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        // 数学定理，ax + by = z, bezout's identity性质
        gcd(x, y)返回 x 和 y 的最大公因数
        if(x + y < target){
            return false;
        }
        if(y == 0 || x == 0){
            return target == 0 || x + y == target;
        }
        return target % gcd(x, y) == 0;
    }
};
// @lc code=end

