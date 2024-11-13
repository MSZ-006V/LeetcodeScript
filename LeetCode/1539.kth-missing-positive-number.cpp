/*
 * @lc app=leetcode id=1539 lang=cpp
 *
 * [1539] Kth Missing Positive Number
 */

// @lc code=start
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> numset(arr.begin(), arr.end());
        int index = 0;
        while(k > 0){
            index++;
            if(numset.find(index) == numset.end()){
                k--;
            }
        }
        return index;
    }
};
// @lc code=end

