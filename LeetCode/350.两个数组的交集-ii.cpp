/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ht;
        vector<int> result;

        for(auto num : nums1){
            ht[num]++;
        }
        for(auto num : nums2){
            if(ht.find(num) != ht.end()){
                if(ht[num] != 0){
                    result.push_back(num);
                    ht[num]--;
                }
            }
        }
        
        return result;
    }
};
// @lc code=end

