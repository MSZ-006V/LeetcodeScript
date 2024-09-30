/*
 * @lc app=leetcode id=1248 lang=cpp
 *
 * [1248] Count Number of Nice Subarrays
 */

// @lc code=start
class Solution {
public:
    bool isOdd(int k){
        return k%2 == 1?true:false;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> array(nums.size(), 0);
        for(int i = 0; i < nums.size(); ++i){
            if(isOdd(nums[i])){
                array[i] = 1;
            }
        }

        int ans = 0, sum = 0;
        unordered_map<int, int> ht;
        ht[0] = 1;
        for(int i = 0; i < nums.size(); ++i){
            sum += array[i];
            if(ht.find(sum - k) != ht.end()){
                ans += ht[sum - k];
            }
            ht[sum]++;
        }
        return ans;
    }
};
// @lc code=end

