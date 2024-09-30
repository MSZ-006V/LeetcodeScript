/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */

// @lc code=start
class Solution {
public:
    int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    int islandPerimeter(vector<vector<int>>& grid) {
        int length = 0;
        int row = grid.size();
        int col = grid[0].size();
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(grid[i][j] != 0){
                    for(int k = 0; k < 4; ++k){
                        int next_x = i + dir[k][0];
                        int next_y = j + dir[k][1];
                        if(next_x < 0 
                        || next_x >= row 
                        || next_y < 0 
                        || next_y >= col
                        || grid[next_x][next_y] == 0){
                            length++;
                        }
                    }
                }
            }
        }
        return length;
    }
};
// @lc code=end

