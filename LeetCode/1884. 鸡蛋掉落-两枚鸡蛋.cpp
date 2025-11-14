class Solution {
public:
    int twoEggDrop(int n) {
        // tc O(n^2), sc O(n)
        vector<int> dp(1001, INT_MAX);
        // dp[i] 表示：测试 i 层楼，最少需要多少次（最坏情况）
        dp[0] = 0;

        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= i; ++j){
                // 情况1：鸡蛋碎了 -> 需要在 j-1 层楼继续测，剩下 i-j 不用测
                // 情况2：鸡蛋没碎 -> 需要在上面的 i-j 层继续测
                // 最坏情况 = max(碎的情况, 没碎的情况)
                // 再加上这一次尝试 +1
                dp[i] = min(dp[i], max(j, dp[i - j] + 1));
            }
        }
        
        return dp[n];
    }
    // 可以用数学方法解决，但这道题实际上是dp题
};