class Solution {
public:
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    int n;
    int m;
    int bfs(vector<vector<int>>& grid, int x, int y){
        int dis = 1;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> que;
        que.push({x, y});
        visited[x][y] = true;

        while(!que.empty()){
            int size = que.size();

            for(int k = 0; k < size; ++k){
                auto cur = que.front(); que.pop();

                for(int i = 0; i < 4; ++i){
                    int nx = cur.first + dir[i][0];
                    int ny = cur.second + dir[i][1];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny] || grid[nx][ny] == -1) continue;
                    if(grid[nx][ny] == 0) return dis;
                    que.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }

            dis++;
        }

        return -1;
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] > 0){
                    int dis = bfs(grid, i, j);
                    grid[i][j] = dis == -1? 2147483647 : dis;
                }
            }
        }
    }
};
