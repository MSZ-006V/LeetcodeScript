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
        // gcd(x, y)返回 x 和 y 的最大公因数
        if(x + y < target){
            return false;
        }
        if(y == 0 || x == 0){
            return target == 0 || x + y == target;
        }
        return target % gcd(x, y) == 0;
    }
};

// 简化版本
class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(x + y < target) return false;

        return target % gcd(x, y) == 0;
    }
};

// 定理
// 对于任意整数a，b（不全为0），存在整数x，y，使得
// ax + by = gcd（a，b）
// @lc code=end

