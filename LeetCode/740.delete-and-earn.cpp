/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // 对一个元素有两种操作，删或者不删
        unordered_map<int, int> ht;
        sort(nums.begin(), nums.end());
        vector<int> dp = {0, nums[0]};
        ht[nums[0]] = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            ht[nums[i]]++;
            if(nums[i] != dp.back())
                dp.push_back(nums[i]);
        }

        int last = dp[1];
        dp[1] = dp[1] * ht[dp[1]];
        for(int i = 2; i < dp.size(); ++i)
        {
            if(dp[i] - last == 1){
                last = dp[i];
                dp[i] = max(dp[i-1], dp[i-2] + dp[i] * ht[dp[i]]);
            }
            else{
                last = dp[i];
                dp[i] = dp[i-1] + dp[i] * ht[dp[i]];
            }
        }

        return dp[dp.size() - 1];
    }
};
// @lc code=end

