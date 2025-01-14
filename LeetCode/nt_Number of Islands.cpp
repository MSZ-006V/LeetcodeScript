class Solution {
public:
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    int n;
    int m;

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y){
        visited[x][y] = true;
        for(int i = 0; i < 4; ++i){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(!visited[nx][ny] && grid[nx][ny] == '1'){
                dfs(grid, visited, nx, ny);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int cnt = 0;

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == '1' && !visited[i][j]){
                    cnt++;
                    dfs(grid, visited, i, j);
                }
            }
        }

        return cnt;
    }
};
