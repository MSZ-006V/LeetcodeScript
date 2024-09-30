/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
private: 
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return {};

        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
        int node_num = matrix.size() * matrix[0].size();
        vector<int> result(node_num);
        int x = 0, y = 0;
        int direction = 0;

        for(int i = 0; i < node_num; ++i){
            visited[x][y] = true;
            result[i] = matrix[x][y];
            int next_x = x + dir[direction][0];
            int next_y = y + dir[direction][1];

            if(next_x < 0 || next_y < 0 || next_x >= matrix.size() || next_y >= matrix[0].size() || visited[next_x][next_y]){
                // 一定要把判断visited[next_x][next_y]放在最后面，因为有可能是越界的
                // 放在前面先判断就会导致数组访问越界，一定要放在最后面
                direction = (direction + 1) % 4;
            }
            x += dir[direction][0];
            y += dir[direction][1];
        }
        return result;
    }
};
// @lc code=end

