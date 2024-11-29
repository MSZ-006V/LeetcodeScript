/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 时间复杂度O(n)，空间复杂度O(1)
        // 就遍历一次，肯定必须要从cur_gas是正的油站开始走，并且走完一圈后total_gas必须是大于等于0的
        // 所以就这么遍历一次，就可以知道了，比较巧妙
        int cur_gas = 0;
        int total_gas = 0;
        int start = 0;
        for(int i = 0; i < gas.size(); ++i){
            cur_gas += gas[i] - cost[i];
            total_gas += gas[i] - cost[i];
            if(cur_gas < 0){
                start = i + 1;
                cur_gas = 0;
            }
        }

        if(total_gas < 0) return -1;
        return start;
    }
};
// @lc code=end

