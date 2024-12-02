/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution {
private:
    int area;
    int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    int n;
    int m;
public:
    void DFS(vector<vector<int>>& grid, int x, int y, int& tarea){
        tarea++;
        grid[x][y] = 0;

        for(int i = 0; i < 4; ++i){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] == 0) continue;
            
            DFS(grid, nx, ny, tarea);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // 公式化图遍历
        // time complexity is O(n * m), 空间复杂度是O(n * m)因为是递归
        // 内层函数由于对于每一个单元格只会访问一次，所以不会是O(n * m * k)
        // 在最坏情况下（整个网格都是一个连通分量），算法访问所有的n * m个单元格，最后每个单元格也是访问一次
        // 所以最坏的时间复杂度也就是O(n * m)
        area = 0;
        n = grid.size();
        m = grid[0].size();

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 1){
                    int temp_area = 0;
                    DFS(grid, i, j, temp_area);
                    area = max(temp_area, area);
                }
            }
        }

        return area;
    }
};
// @lc code=end

