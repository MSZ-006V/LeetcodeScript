/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const auto& x, const auto& y){
            return x[1] < y[1];
        });
        int cnt = 1;
        for(int i = 1; i < points.size(); ++i){
            if(points[i][0] <= points[i - 1][1]){
                points[i][1] = min(points[i][1], points[i - 1][1]);
            }
            else{
                cnt++;
            }
        }
        return cnt;
    }
};
// @lc code=end

