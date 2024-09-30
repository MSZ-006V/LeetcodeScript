/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> c(n, 0);
        for(int i = 0; i < n; ++i){
            c[nums[i] - 1] = 1;
        }
        vector<int> result;
        for(int i = 0; i < n; ++i){
            if(c[i] == 0){
                result.push_back(i + 1);
            }
        }
        return result;
    }
};
// @lc code=end

