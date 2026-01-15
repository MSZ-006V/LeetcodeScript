class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // leetcode 494
        // tc: O(n * sum), sc: O(sum)
        // 基础思想很容易明白，其实就是转换为01背包问题（每个数只能用一次）
        // target_v就是数字前面需要放置正好的数字和，而剩下的就全是负号，加起来正好就等于target的值
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(abs(target) > sum || (target + sum) % 2 == 1) return 0;

        int target_v = (target + sum) / 2;
        vector<int> dp(target_v + 1, 0);
        dp[0] = 1;

        for(auto num : nums){
            for(int i = target_v; i >= num; --i){
                dp[i] += dp[i - num];
            }
        }

        return dp[target_v];
    }
};
