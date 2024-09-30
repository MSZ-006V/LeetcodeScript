/*
 * @lc app=leetcode id=2530 lang=cpp
 *
 * [2530] Maximal Score After Applying K Operations
 */

// @lc code=start
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long score = 0;

        for(int i = 0; i < k; ++i){
            int num = pq.top(); pq.pop();
            score += num;
            pq.push((num + 2) / 3);
        }

        return score;
    }
};
// @lc code=end

