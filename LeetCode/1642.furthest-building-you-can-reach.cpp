/*
 * @lc app=leetcode id=1642 lang=cpp
 *
 * [1642] Furthest Building You Can Reach
 */

// @lc code=start
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // 使用优先队列 + 贪心的思路
        // 就是先不管什么情况，先使用梯子，pq里面存的都是使用梯子的情况，pq是一个从小到大的队列
        // 当pq的需求大于梯子数量，就开始用brick
        // 梯子肯定是要在最高距离用，所以取出最小的一个高度用brick补齐
        // 当需要brick的数量大于所拥有的数量的时候，这时候这栋楼i是上不去的，所以返回是i - 1
        // 此时pq队列的长度就正好是梯子的个数，因为pq总是进一个出一个
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        int sumH = 0;
        for(int i = 1; i < n; ++i){
            int deltaH = heights[i] - heights[i - 1];
            if(deltaH > 0){
                pq.push(deltaH);
                if(pq.size() > ladders){
                    sumH += pq.top(); pq.pop();
                }
                if(sumH > bricks){
                    return i - 1;
                }
            }
        }

        return n - 1;
    }
};
// @lc code=end

