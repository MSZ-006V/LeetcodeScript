/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 */

// @lc code=start
class Solution {
private:
    const int dir[8][2] = {0, 1, 0, -1, 1, 0, -1, 0, -1, -1, 1, -1, -1, 1, 1, 1};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // time complexity is O(n^2), space complexity is O(n);
        // 最坏情况下第一个for循环会包含所有的点，所以是O(n^2)
        int n = grid.size();
        if(grid[0][0] == 1) return -1;
        if(grid[0][0] == 0 && n == 1) return 1;
    
        queue<pair<int, int>> que;
        que.push(make_pair(0, 0));
        int cnt = 0;

        while(!que.empty()){
            int size = que.size();
            cnt++;
            for(int i = 0; i < size; ++i){
                auto cur = que.front(); que.pop();
                for(int k = 0; k < 8; ++k){
                    int nx = cur.first + dir[k][0];
                    int ny = cur.second + dir[k][1];

                    if(nx < 0 || ny < 0 || nx >= n || ny >= n || grid[nx][ny] != 0) continue;
                    if(nx == n - 1 && ny == n - 1) return cnt + 1;
                    que.push(make_pair(nx, ny));
                    grid[nx][ny] = 1;
                }
            }
        }

        return -1;
    }
};
// @lc code=end

