/*
 * @lc app=leetcode id=3066 lang=cpp
 *
 * [3066] Minimum Operations to Exceed Threshold Value II
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, std::greater<long long>> pq(nums.begin(), nums.end());
        int count = 0;

        while(pq.top() < k){
            long long x = pq.top(); pq.pop();
            long long y = pq.top(); pq.pop();
            count++;
            
            pq.push(x * 2 + y);
        }

        return count;
    }
};
// @lc code=end

