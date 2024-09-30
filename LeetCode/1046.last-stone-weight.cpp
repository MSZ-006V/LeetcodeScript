/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto stone:stones){
            pq.push(stone);
        }
        while(pq.size() > 1){
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            if(x - y != 0){
                pq.push(abs(x - y));
            }
        }
        if(pq.size() == 1){
            return pq.top();
        }
        else{
            return 0;
        }
    }
};
// @lc code=end

