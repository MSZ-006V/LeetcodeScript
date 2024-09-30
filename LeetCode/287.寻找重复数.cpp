/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution {
public:
    // int findDuplicate(vector<int>& nums) {
    //     unordered_set<int> num_set;
    //     for(int i = 0; i < nums.size(); ++i){
    //         if(num_set.count(nums[i]) != 0){
    //             return nums[i];
    //         }
    //         num_set.insert(nums[i]);
    //     }
    //     return 0;
    // }
    int findDuplicate(vector<int>& nums) {
        // 利用了一个性质，即对于这个nums数组
        // 假设3是重复的数组，数组中包含数字有1,2,3,4,5
        // 那么数组数字构成一定是1,2,3,3,4,5
        // 小于等于3的数字有4个，如果3不是重复的数组的话
        // 数组构成为1,2,3,4,4,5，小于等于3的数字有3个
        // 所以，对于一个数字i，如果在数组中小于等于它的数字个数大于i的话，那就说明，重复数字是大于这个数组i的
        // 反之则说明重复数字是小于数字i的
        int len = nums.size(); // n + 1 = len, n = len - 1

        // 在 [1..n] 查找 nums 中重复的元素
        int left = 1;
        int right = len - 1;
        while (left < right) {
            int mid = (left + right) / 2;

            // nums 中小于等于 mid 的元素的个数
            int count = 0;
            for (int num : nums) {
                if (num <= mid) {
                    count++;
                }
            }

            if (count > mid) {
                // 下一轮搜索的区间 [left..mid]
                right = mid;
            } else {
                // 下一轮搜索的区间 [mid + 1..right]
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end

