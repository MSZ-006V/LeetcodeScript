class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_f = 0; // 计算最大子数组和的 DP 数组（空间优化成一个变量）
        int max_s = INT_MIN; // 最大子数组和，不能为空
        int min_f = 0; // 计算最小子数组和的 DP 数组（空间优化成一个变量）
        int min_s = 0; // 最小子数组和，可以为空（元素和为 0）
        int sum = 0; // nums 的元素和

        for (int x : nums) {
            // 53. 最大子数组和（空间优化写法）
            max_f = max(max_f, 0) + x;
            max_s = max(max_s, max_f);
            min_f = min(min_f, 0) + x;
            min_s = min(min_s, min_f);
            sum += x;
        }

        return max_s < 0 ? max_s : max(max_s, sum - min_s);
    }
};