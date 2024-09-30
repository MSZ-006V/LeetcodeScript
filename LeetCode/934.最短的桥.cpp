/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 */

// @lc code=start
class Solution {
private:
    int n;
    int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
public:
    void dfs(int x, int y, 
    vector<vector<int>>& grid, 

    queue<pair<int, int>>& queue){
        if(x < 0 || y < 0 || x >= n || y >= n || grid[x][y] != 1) return;

        grid[x][y] = -1;
        queue.push({x, y});
        for(int i = 0; i < 4; ++i){
            dfs(x + dir[i][0], y + dir[i][1], grid, queue);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        // 使用DFS+BDS的搜索方法，先使用DFS搜索出一个岛全部的点的位置集合，即que
        // 然后遍历这个que，一代一代的遍历，所以要使用一个sz变量
        // 每一次遍历把周围为0的点加进来，同时把这些点的值全部变为-1，表示已经访问过了
        // 由于使用BDS进行遍历，当找到另外一个岛的时候，距离一定是最短的
        n = grid.size();
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    queue<pair<int, int>> que;
                    dfs(i, j, grid, que);
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

