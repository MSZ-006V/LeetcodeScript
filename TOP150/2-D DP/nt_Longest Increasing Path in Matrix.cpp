class Solution {
public:
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    int row, col;

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // tc: O(m * n), sc: O(m * n)
        // 这题实际上都不能算dp，就是一个普通的dfs，然后记录搜索过得位置（记录最长路径）
        row = matrix.size();
        col = matrix[0].size();

        vector<vector<int>> memo(row, vector<int>(col, 0));
        int ans = 0;
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                ans = max(ans, dfs(i, j, memo, matrix));
            }
        }

        return ans;
    }

    int dfs(int x, int y, vector<vector<int>>& memo, vector<vector<int>>& matrix){
        if(memo[x][y] != 0){
            return memo[x][y];
        }

        ++memo[x][y];
        for(int i = 0; i < 4; ++i){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if(nx < 0 || ny < 0 || nx >= row || ny >= col || matrix[nx][ny] <= matrix[x][y]) continue;
            memo[x][y] = max(memo[x][y], dfs(nx, ny, memo, matrix) + 1);
        }
        return memo[x][y];
    }
};
