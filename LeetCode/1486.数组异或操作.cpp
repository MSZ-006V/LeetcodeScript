/*
 * @lc app=leetcode.cn id=1486 lang=cpp
 *
 * [1486] 数组异或操作
 */

// @lc code=start
class Solution {
public:
    int xorOperation(int n, int start) {
        int pre = 0;
        for(int i = 0; i < n; ++i){
            pre = pre ^ (start + (2 * i));
        }
        return pre;

    }
};
// @lc code=end

