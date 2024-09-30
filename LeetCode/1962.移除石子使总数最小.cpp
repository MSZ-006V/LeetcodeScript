/*
 * @lc app=leetcode.cn id=1962 lang=cpp
 *
 * [1962] 移除石子使总数最小
 */

// @lc code=start
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());
        for(int i = 0; i < k; ++i){
            int cur = pq.top();pq.pop();
            pq.push(cur - (cur / 2));
        }
        int sum = 0;
        while(pq.size() != 0){
            int cur = pq.top();pq.pop();
            sum += cur;
        }
        return sum;
    }
};
// @lc code=end

