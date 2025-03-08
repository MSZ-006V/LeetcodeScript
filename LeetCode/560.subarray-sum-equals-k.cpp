/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> ht;
        ht[0] = 1;
        int sum = 0;
        int ret = 0;

        for(auto num : nums){
            sum += num;
            if(ht.contains(sum - k)){
                ret += ht[sum - k];
            }
            ht[sum]++;
        }

        return ret;
    }
};
// @lc code=end

