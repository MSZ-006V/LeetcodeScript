/*
 * @lc app=leetcode id=694 lang=cpp
 *
 * [694] Number of Distinct Islands
 */

// @lc code=start
class Solution {
public:
    int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    void dfs(vector<vector<int>>& grid, string& pattern, int ix, int iy, int x, int y){
        grid[x][y] = 0;
        pattern += std::to_string(x - ix) + std::to_string(y - iy);

        for(int i = 0; i < 4; ++i){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if(nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] == 0) continue;
            dfs(grid, pattern, ix, iy, nx, ny);
        }
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        // 这道题用一个字符串编码来解决，因为每一次遍历肯定都是从岛的左上角顶点开始遍历
        // 使用每一个点与左上角顶点的距离进行编码，每一个岛的编码都是独一无二的
        // 然后插入一个unordered_set进行记录，保证可以统计到所有不同类型的岛
        unordered_set<string> island_pattern;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 1){
                    string pattern = "";
                    dfs(grid, pattern, i, j, i, j);
                    island_pattern.insert(pattern);
                }
            }
        }

        return island_pattern.size();
    }
};
// @lc code=end

