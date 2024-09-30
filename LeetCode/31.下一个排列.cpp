/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        for(int i = n - 1; i >= 0; --i){
            for(int j = n - 1; j > i; --j){
                if(nums[j] > nums[i]){
                    cout << nums[i] << nums[j] << endl;
                    swap(nums[i], nums[j]); // j<i, 遇到nums[i] > nums[j], 就把两个元素交换
                    reverse(nums.begin() + i + 1, nums.end()); // 把i+1后面的部分进行翻转
                    return;
                }
            }
        }
        reverse(nums.begin(), nums.end());
    }
};
// @lc code=end

