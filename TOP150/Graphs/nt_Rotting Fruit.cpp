class Solution {
public:
    int n;
    int m;
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> que;

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 2){
                    que.push({i, j});
                }
            }
        }

        int time = 0;
        while(!que.empty()){
            int size = que.size();
            time++;
            for(int i = 0; i < size; ++i){
                auto cur = que.front(); que.pop();
                visited[cur.first][cur.second] = true;

                for(int k = 0; k < 4; ++k){
                    int nx = cur.first + dir[k][0];
                    int ny = cur.second + dir[k][1];

                    if(nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny] || grid[nx][ny] == 0 || grid[nx][ny] == 2) continue;

                    grid[nx][ny] = 2;
                    que.push({nx, ny});
                }
            }
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return time == 0? 0 : time - 1;

    }
};
