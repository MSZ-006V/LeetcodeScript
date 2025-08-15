/*
 * @lc app=leetcode id=1049 lang=cpp
 *
 * [1049] Last Stone Weight II
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // 和494比较类似，可以参考494的思路
        int sum = accumulate(stones.begin(), stones.end(), 0);
        cout << sum << endl;
        int target = sum / 2;
        cout << target << endl;

        vector<int> dp(target + 1, 0);
        for(auto stone : stones){
            for(int i = target; i > stone - 1; --i){
                dp[i] = max(dp[i], dp[i - stone] + stone);
            }
        }

        for(int i = 0; i < target + 1; ++i){
            cout << dp[i] << ' ';
        }
        return sum - 2 * dp[target];
    }
};
// @lc code=end

