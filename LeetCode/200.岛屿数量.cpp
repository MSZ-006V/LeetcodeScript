/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
private:
    int island_val = 0;
    int n = 0;
    int m = 0;
    int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
public:
    void BFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y){
        visited[x][y] = true; // 把访问过的地方打上标记，就不会重复访问了
        for(int i = 0; i < 4; ++i){
            int next_x = x + dir[i][0];
            int next_y = y + dir[i][1];
            if(next_x < 0 || next_y < 0 || next_x >= n || next_y >= m) continue;
            if(visited[next_x][next_y] == false && grid[next_x][next_y] == '1'){
                BFS(grid, visited, next_x, next_y);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == '1' && visited[i][j] == false){
                    island_val++; // 进入某一座岛屿就开始计数
                    BFS(grid, visited, i, j);
                }
            }
        }
        return island_val;
    }
};
// @lc code=end

