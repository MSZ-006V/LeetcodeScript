/*
 * @lc app=leetcode.cn id=930 lang=cpp
 *
 * [930] 和相同的二元子数组
 */

// @lc code=start
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // 实际上，对于数组的某个下标j，在j之前的所有不同组合的子数组的和，都存储在哈希表里面了
        // 包括了所有种类的和，所以对于这个下标j，只需要在ht中查询以j为结尾的前缀和-目标值的个数
        // 就能够得出以j结尾的子数组且满足条件的个数，统计这些个数就可以了
        unordered_map<int, int> ht;
        ht[0] = 1;
        int sum = 0;
        int ret = 0;
        for(auto num : nums){
            sum += num;
            ret += ht[sum - goal];
            ht[sum]++;
        }
        return ret;
    }
};
// @lc code=end

