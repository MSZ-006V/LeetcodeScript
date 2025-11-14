/*
 * @lc app=leetcode.cn id=974 lang=cpp
 *
 * [974] 和可被 K 整除的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // 根据同余定理
        // 对于两个数a和b，如果(a - b) mod k == 0, 则有 a mod k等于 b mod k
        // 所以，对于前缀和sum，直接在哈希表中找sum % k的个数，就相当于找到了另外对于的那个b
        // 通过哈希表就能得出那个b的个数，加上即可
        unordered_map<int, int> ht;
        ht[0] = 1;
        int sum = 0;
        int ret = 0;
        for(auto num : nums){
            sum += num;
            int mod_result = (sum % k + k) % k;
            // 在cpp里面，负数取模例子如下
            // -5 % 3 = -2, -5 % -3 = -2
            // a % b 的符号等于a的符号
            // 由于这个数组中包含负数，所以需要对负数取模的情况特殊处理，就如上面那个式子
            // 主要操作其实还是完成sum % k, 写的那么复杂只是为了得到正确的数
            ret += ht[mod_result];
            ht[mod_result]++;
        }
        return ret;
    }
};
// @lc code=end

