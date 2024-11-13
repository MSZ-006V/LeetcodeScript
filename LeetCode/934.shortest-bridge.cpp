/*
 * @lc app=leetcode id=934 lang=cpp
 *
 * [934] Shortest Bridge
 */

// @lc code=start
class Solution {
private:
    int n;
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
public:
    void dfs(int x, int y, queue<pair<int, int>>& que, vector<vector<int>>& grid){
        if(x < 0 || y < 0 || x >= n || y >= n || grid[x][y] != 1) return;

        grid[x][y] = -1;
        que.push({x, y});
        for(int i = 0; i < 4; ++i){
            dfs(x + dir[i][0], y + dir[i][1], que, grid);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    queue<pair<int, int>> que;
                    dfs(i, j, que, grid);
                    int step = 0;

                    while(que.size() != 0){
                        int sz = que.size();
                        for(int k = 0; k < sz; ++k){
                            auto [x, y] = que.front();que.pop();
                            for(int index = 0; index < 4; ++index){
                                int nx = x + dir[index][0];
                                int ny = y + dir[index][1];
                                if(nx >= 0 && ny >= 0 && nx < n && ny < n){
                                    if(grid[nx][ny] == 1){
                                        return step;
                                    }
                                    else if(grid[nx][ny] == 0){
                                        que.push({nx, ny});
                                        grid[nx][ny] = -1;
                                    }
                                }
                            }
                        }
                        step++;
                    }
                }
            }
        }
        return 0;
    }
};
// @lc code=end

