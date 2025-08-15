class Solution {
public:
    int n;
    int m;
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int& area){
        area++;
        visited[x][y] = true;

        for(int i = 0; i < 4; ++i){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] == 0) continue;
            if(grid[nx][ny] == 1 && !visited[nx][ny]){
                dfs(grid, visited, nx, ny, area);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // 简单题
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int max_val = 0;

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 1 && !visited[i][j]){
                    int val = 0;
                    dfs(grid, visited, i, j, val);
                    max_val = max(max_val, val);
                }
            }
        }

        return max_val;
    }
};
