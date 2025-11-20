class Solution {
public:
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        queue<pair<int, int>> que;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 2){
                    que.push({i, j});
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int time = 0;
        while(fresh > 0 && !que.empty()){
            int size = que.size();
            
            for(int i = 0; i < size; ++i){
                auto cur = que.front(); que.pop();

                for(int i = 0; i < 4; ++i){
                    int nx = cur.first + dir[i][0];
                    int ny = cur.second + dir[i][1];

                    if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1){
                        grid[nx][ny] = -2;
                        que.push({nx, ny});
                        fresh--;
                    }
                }
            }
            time++;
        }

    
        return fresh == 0? time : -1;
    }
};
