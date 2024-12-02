/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution {
private:
    const int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // time complexity is O(n ^ 2), space complexity is O(n ^ 2)
        queue<pair<int, int>> que;
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 2){
                    que.push(make_pair(i, j));
                }
            }
        }
        int cnt = -1;
        while(!que.empty()){
            cnt++;
            int size = que.size();
            for(int i = 0; i < size; ++i){
                auto cur = que.front(); que.pop();
                for(int j = 0; j < 4; ++j){
                    int nx = cur.first + dir[j][0];
                    int ny = cur.second + dir[j][1];

                    if(nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 1) continue;
                    que.push(make_pair(nx, ny));
                    grid[nx][ny] = 2;
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

        return max(cnt, 0);
    }
};
// @lc code=end

