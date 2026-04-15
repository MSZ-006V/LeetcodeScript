class Solution {
public:
    int dir[8][2] = {0, 1, 0, -1, 1, 0, -1, 0, -1, -1, 1, 1, -1, 1, 1, -1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {        
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1]) return -1;
        if (n == 1) return 1;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> que;
        que.push({0, 0});
        visited[0][0] = true;

        int res = 1;

        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                auto cur = que.front(); que.pop();
                for (auto d : dir) {
                    int nx = cur.first + d[0];
                    int ny = cur.second + d[1];
                    if (nx == n - 1 && ny == n - 1) return res + 1;

                    if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny] && grid[nx][ny] == 0) {
                        que.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }
            res++;
        }

        return -1;
    }
};