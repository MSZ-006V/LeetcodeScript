/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 位运算重要题目
        // ^ 是异或运算，异或运算的性质如下
        // 任何数和 0 做异或运算，结果仍然是原来的数，即 a⊕0=a
        // 任何数和其自身做异或运算，结果是 0，即 a⊕a=0
        // 异或运算满足交换律和结合律，即 a⊕b⊕a=b⊕a⊕a=b⊕(a⊕a)=b⊕0=b
        // 所以，将数组中所有的数，按照顺序进行异或运算，最后的ret结果就是没重复的那个数
        int ret = 0;
        for(int num:nums){
            ret = ret ^ num;
        }
        return ret;
    }
};
// @lc code=end

