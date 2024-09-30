/*
 * @lc app=leetcode.cn id=1208 lang=cpp
 *
 * [1208] 尽可能使字符串相等
 */

// @lc code=start
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        // 这道题的思路和1004完全一样，都是滑动窗口类型
        vector<int> cost(s.size(), 0);
        for(int i = 0; i < s.size(); ++i){
            cost[i] = abs(s[i] - t[i]);
        }
        int left = 0, ans = 0, window_cost = 0;
        for(int right = 0; right < cost.size(); ++right){
            window_cost += cost[right];
            while(window_cost > maxCost){
                window_cost -= cost[left++];
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end

