class Solution {
public:
    int climbStairs(int n) {
        // tc O(n), sc O(n) 可以优化到O(1)
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i < n + 1; ++i){
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};
