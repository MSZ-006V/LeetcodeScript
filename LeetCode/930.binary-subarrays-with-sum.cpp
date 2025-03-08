/*
 * @lc app=leetcode id=930 lang=cpp
 *
 * [930] Binary Subarrays With Sum
 */

// @lc code=start
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> ht;
        ht[0] = 1;
        int result = 0;
        int sum = 0;
        for(auto num : nums){
            sum += num;
            if(ht.contains(sum - goal)){
                result += ht[sum - goal];
            }
            ht[sum]++;
        }

        return result;
    }
};
// @lc code=end

