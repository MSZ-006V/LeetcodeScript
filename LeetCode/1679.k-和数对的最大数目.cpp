/*
 * @lc app=leetcode.cn id=1679 lang=cpp
 *
 * [1679] K 和数对的最大数目
 */

// @lc code=start
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> ht;
        for(auto& num : nums){
            auto it = ht.find(k - num);
            if(it != ht.end() && it->second != 0){
                ans++;
                it->second--;
            }
            else{
                ht[num]++;
            }
        }
        return ans;
    }
};
// @lc code=end

