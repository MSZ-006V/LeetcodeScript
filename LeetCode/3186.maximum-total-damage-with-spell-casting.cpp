/*
 * @lc app=leetcode id=3186 lang=cpp
 *
 * [3186] Maximum Total Damage With Spell Casting
 */

// @lc code=start
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        // 如果后面看这道题没搞懂的话，把j和f数组打印出来就知道了
        // j的作用是找到当前偷盗这家的价值x - 2后最大的那一家
        // 只用管一边的x-1，x-2就可以，另一边不用管，这样也是简化
        // 对于默认例子[1, 3, 4], j的输出是0, 0, 1，当i指向4的时候，j指向1表示dp[j]是满足条件最大的价值
        // 而对于1，3，j都是指向0，表示dp[0]才是满足条件最大的价值，然而dp[0]一直都是0
        // 因为dp数组赋值从i + 1开始的
        unordered_map<int, int> cnt;
        for (int x : power) {
            cnt[x]++;
        }

        vector<pair<int, int>> a(cnt.begin(), cnt.end());
        ranges::sort(a);

        int n = a.size();
        vector<long long> dp(n + 1);
        for (int i = 0, j = 0; i < n; i++) {
            auto& [x, c] = a[i];
            while (a[j].first < x - 2) {
                j++;
            }
            dp[i + 1] = max(dp[i], dp[j] + (long long) x * c);
        }
        return dp[n];
    }
};
// @lc code=end

