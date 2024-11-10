/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(auto num : nums){
            // 直接在结果数组中查找
            auto it = ranges::lower_bound(res.begin(), res.end(), num);
            if(it == res.end()){ // 没找到就说明这是一个新的可以递增的序列
                res.push_back(num);
            }
            else{ // 如果找到修改res，可以减小数组每一个元素递增之间的范围，得到更大的递增区间
                *it = num;
            }
        }
        return res.size();
    }
};
// @lc code=end

