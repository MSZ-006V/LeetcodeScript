class Solution {
public:
    int n, m;
    int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

    void dfs(vector<vector<char>>& grid, int x, int y){
        grid[x][y] = '0';

        for(int i = 0; i < 4; ++i){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == '1'){
                dfs(grid, nx, ny);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        n = grid.size();
        m = grid[0].size();
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    island++;
                }
            }
        }

        return island;
    }
};
