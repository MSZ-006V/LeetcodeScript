/*
 * @lc app=leetcode id=3275 lang=cpp
 *
 * [3275] K-th Nearest Obstacle Queries
 */

// @lc code=start
class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        int len = queries.size();
        vector<int> res(len, -1);
        priority_queue<long long> pq;
        for(int i = 0; i < len; ++i){
            pq.push(abs(queries[i][0]) + abs(queries[i][1]));
            if(pq.size() > k){ // 如果元素个数超过了，就弹出多余的太大的数
                pq.pop(); // 因为一次只push一个元素，所以pop一个元素就可以了
            }
            if(pq.size() == k){ 
                // 思路很巧妙，找第k个最小的数，就用最大堆来维护
                // 保证堆中元素个数是k，则堆中第一个数就是第k小的数了
                res[i] = pq.top();
            }
        }

        return res;
    }
};
// @lc code=end

