/*
 * @lc app=leetcode id=2706 lang=cpp
 *
 * [2706] Buy Two Chocolates
 */

// @lc code=start
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        priority_queue<int, vector<int>, greater<int>> pq(prices.begin(), prices.end());
        int v1 = pq.top(); pq.pop();
        int v2 = pq.top();
        int left = money - v1 - v2;
        if(left < 0){
            return money;
        }
        else{
            return left;
        }
    }
};
// @lc code=end

