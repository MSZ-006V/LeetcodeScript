class Solution {
    int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size(), COLS = heights[0].size();
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));

        for (int c = 0; c < COLS; ++c) {
            dfs(0, c, pac, heights);
            dfs(ROWS - 1, c, atl, heights);
        }
        for (int r = 0; r < ROWS; ++r) {
            dfs(r, 0, pac, heights);
            dfs(r, COLS - 1, atl, heights);
        }

        vector<vector<int>> res;
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (pac[r][c] && atl[r][c]) { // 如果某一个点(r, c)都能流到atl和atl，那就是结果点，所以必须是两个数组中对应的点都是true
                    res.push_back({r, c});
                }
            }
        }
        return res;
    }

private:
    void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights) {
        ocean[r][c] = true;
        for (int i = 0; i < 4; ++i) {
            int nr = r + dir[i][0], nc = c + dir[i][1];
            if (nr >= 0 && nr < heights.size() && 
                nc >= 0 && nc < heights[0].size() && 
                !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, ocean, heights);
            }
        }
    }
};