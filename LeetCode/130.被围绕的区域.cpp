/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
private:
    int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    int m;
    int n;
public:
    void BFS(vector<vector<char>>& board
    , vector<vector<bool>>& surround, int x, int y){
        surround[x][y] = false;
        for(int i = 0; i < 4; ++i){
            int next_x = x + dir[i][0];
            int next_y = y + dir[i][1];
            if(next_x < 0 || next_y < 0 || next_x >= n || next_y >= m) continue;
            if(board[next_x][next_y] == 'O' && surround[next_x][next_y] == true){
                BFS(board, surround, next_x, next_y);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        // 简单的BFS算法，从四条边开始找，从边上延伸进去的O路径全部都不用变，其他的全部变
        n = board.size();
        m = board[0].size();
        vector<vector<bool>> surrounded(n, vector<bool>(m, true));
        for(int i = 0; i < n; ++i){
            if(board[i][0] == 'O'){
                BFS(board, surrounded, i, 0);
            }
            if(board[i][m - 1] == 'O'){
                BFS(board, surrounded, i, m - 1);
            }
        }
        for(int j = 0; j < m; ++j){
            if(board[0][j] == 'O'){
                BFS(board, surrounded, 0, j);
            }
            if(board[n - 1][j] == 'O'){
                BFS(board, surrounded, n - 1, j);
            }
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(board[i][j] == 'O' && surrounded[i][j] == true){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
// @lc code=end

