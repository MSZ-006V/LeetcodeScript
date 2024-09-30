/*
 * @lc app=leetcode id=2558 lang=cpp
 *
 * [2558] Take Gifts From the Richest Pile
 */

// @lc code=start
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(auto gift:gifts){
            pq.push(gift);
        }
        long long sum = 0;
        for(int i = 0; i < k; ++i){
            int gift = pq.top(); pq.pop();
            gift = int(sqrt(gift));
            pq.push(gift);
        }
        while(!pq.empty()){
            sum += pq.top(); pq.pop();
        }

        return sum;
    }
};
// @lc code=end

