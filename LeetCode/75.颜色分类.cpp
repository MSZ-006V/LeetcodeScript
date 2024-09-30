/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> ht(3, 0);
        for(int i = 0; i < nums.size(); ++i){
            ht[nums[i]] += 1;
        }
        int index = 0;
        for(int i = 0; i < 3; ++i){
            while(ht[i] > 0){
                nums[index] = i;
                index++;
                ht[i]--;
            }
        }
    }
};
// @lc code=end

