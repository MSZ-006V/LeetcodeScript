/*
 * @lc app=leetcode id=1584 lang=cpp
 *
 * [1584] Min Cost to Connect All Points
 */

// @lc code=start
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        auto manhattan_dis = [&](auto a, auto b){
            return abs(a[0] - b[0]) + abs(a[1] + b[1]);
        };
        int n = points.size();
        vector<vector<int>> edge(n, vector<int>(n, 0));
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                edge[i][j] = manhattan_dis(points[i], points[j]);
                edge[j][i] = edge[i][j];
            }
        }

        return 0;
    }
};
// @lc code=end

