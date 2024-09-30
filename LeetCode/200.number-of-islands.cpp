/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
private:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int count;
public:
    void traversal(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y){
        visited[x][y] = true;
        for(int i = 0; i < 4; ++i){
            int next_x = x + dir[i][0];
            int next_y = y + dir[i][1];
            if(next_x < 0 || next_y < 0 || next_x >= grid.size() || next_y >= grid[0].size() || visited[next_x][next_y] || grid[next_x][next_y] == '0'){
                continue;
            }
            traversal(grid, visited, next_x, next_y);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        count = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == '1' && !visited[i][j] ){
                    count++;                
                    traversal(grid, visited, i, j);
                }
            }
        }
        return count;
    }
};
// @lc code=end

