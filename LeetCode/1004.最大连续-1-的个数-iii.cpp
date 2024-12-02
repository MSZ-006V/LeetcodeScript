/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 */

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // 2024.12.1记：重新复习这道题，其实就是灵神的滑动窗口公式模版
        // 维护窗口内的0的个数，永远保证窗口内0的个数是小于等于k的，这样子可以保证窗口内的数字可以全是1（经过翻转后）
        // 统计窗口内 0 的个数 cnt0，则问题转换成在 cnt0 ≤ k 的前提下，窗口大小的最大值。
        int ans = 0, left = 0, cnt0 = 0;
        for(int right = 0; right < nums.size(); ++right){
            cnt0 = cnt0 + (1 - nums[right]); // 如果是1的话，就不统计0的个数
            while(cnt0 > k){
                cnt0 = cnt0 - (1 - nums[left++]); 
                // 先访问nums[left], 然后left++,后缀自增符号
                // 一直进行循环，直到碰到一个0然后减去，减少区间内0的个数
                //cout << "left: " << left << "right: " << right << endl;
            }
            ans = max(ans, right - left + 1); // 不断统计最大值
        }
        return ans;
    }
};
// @lc code=end

