class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // 枚举最后一个被戳破的气球 i
        // dp[left][right] = max(dp[left][i - 1] + dp[i + 1][right] + nums[left - 1] * nums[i] * nums[right + 1])

        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int left = n - 2; left >= 1; --left){
            for(int right = left; right <= n - 2; ++right){
                for(int i = left; i <= right; ++i){
                    int coins = nums[left - 1] * nums[i] * nums[right + 1];
                    coins += dp[left][i - 1] + dp[i + 1][right];
                    dp[left][right] = max(dp[left][right], coins);
                }
            }
        }
        return dp[1][n - 2];
    }
};
