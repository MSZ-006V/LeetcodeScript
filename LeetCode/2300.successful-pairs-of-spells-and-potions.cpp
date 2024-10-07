/*
 * @lc app=leetcode id=2300 lang=cpp
 *
 * [2300] Successful Pairs of Spells and Potions
 */

// @lc code=start
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int length = potions.size(); 
        sort(potions.begin(), potions.end());
        vector<int> result;
        for(auto spell : spells){
            long long target = (success - 1) / spell;
            result.push_back(potions.end() - ranges::upper_bound(potions, target));
        }

        return result;
    }
};
// @lc code=end

