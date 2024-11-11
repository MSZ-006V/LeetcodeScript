/*
 * @lc app=leetcode id=870 lang=cpp
 *
 * [870] Advantage Shuffle
 */

// @lc code=start
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        // 整体思路类似田忌赛马，可以不使用二分查找，不然时间复杂度会很大
        // 不使用二分查找的方法较为复杂，逻辑比较难想
        sort(nums1.begin(), nums1.end());
        vector<int> res;
        for(auto num : nums2){
            auto it = ranges::upper_bound(nums1.begin(), nums1.end(), num);
            if(it == nums1.end()){
                res.push_back(nums1[0]);
                nums1.erase(nums1.begin());
            }
            else{
                res.push_back(*it);
                nums1.erase(it);
            }
        }

        return res;
    }
};
// @lc code=end

