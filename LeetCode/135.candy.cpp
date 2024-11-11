/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        for(int i = 1; i < candies.size(); ++i){
            if(ratings[i] > ratings[i - 1]){
                if(candies[i] <= candies[i - 1]){
                    candies[i] = candies[i - 1] + 1;
                }
            }
        }
        for(int i = candies.size() - 2; i > -1; --i){
            if(ratings[i] > ratings[i + 1]){
                if(candies[i] <= candies[i + 1]){
                    candies[i] = candies[i + 1] + 1;
                }
            }
        }
        // 顺序扫描一遍，逆序扫描一遍即可
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
// @lc code=end

