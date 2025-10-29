class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // tc O(coins.size() * amount), sc O(amount)
        // leetcode 518, 322
        vector<int> dp(amount + 1, 0);
        dp[0] = 1; // dp[i] 代表金额为i时，有dp[i]种兑换方式，所以当金额为0，就只有1种方式，什么都不用

        for(auto coin : coins){
            for(int i = coin; i < amount + 1; ++i){
                dp[i] += dp[i - coin];
            }
        }

        return dp[amount];
    }
};
    