/*
 * @lc app=leetcode id=1151 lang=cpp
 *
 * [1151] Minimum Swaps to Group All 1's Together
 */

// @lc code=start
class Solution {
public:
    int minSwaps(vector<int>& data) {
        // 也是一个滑动窗口，很经典的滑动窗口模板套路
        int width = accumulate(data.begin(), data.end(), 0);
        int left = 0;
        int sum = 0;
        int max_window_sum = 0;
        int ans = width;
        for(int right = 0; right < data.size(); ++right){
            sum += data[right]; // 先加
            if(right - left + 1 > width){ // 如果不符合区间长度了，就弹出，然后减小
                sum -= data[left];
                left++;
            }
            if(right - left + 1 == width && sum > max_window_sum){ // 如果窗口大小符合，并且窗口元素和更大
                max_window_sum = sum; // 记录更大的窗口元素和，越大的和证明越少移动次数
                ans = min(ans, width - sum);
                // cout << ans << ' ' << max_window_sum << endl;
            }
        }
        return ans;
    }
};
// @lc code=end

