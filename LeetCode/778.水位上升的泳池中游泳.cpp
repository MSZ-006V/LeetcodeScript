class Solution {
public:
    // 使用二分查找结合DFS判断是否可以从左上角游到右下角
    int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, -1));

        auto check = [&](int mx) -> bool {
            auto dfs = [&](this auto &&dfs, int i, int j) -> bool {
                if(i == n - 1 && j == n - 1) return true;

                visited[i][j] = mx;
                for(auto &[dx, dy] : dir){
                    int x = i + dx, y = j + dy;
                    if(x >= 0 && y >= 0 && x < n && y < n && grid[x][y] <= mx && visited[x][y] != mx && dfs(x, y)){
                        return true;
                    }
                }

                return false;
            };

            return dfs(0, 0);
        };

        int left = max(grid[0][0], grid[n - 1][n - 1]), right = n * n - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(check(mid)){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return left;
    }
};