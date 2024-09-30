/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 */

// @lc code=start
class Solution {
private:
    int dir[8][2] = {0, -1, 0, 1, 1, 0, -1, 0, -1, 1, 1, 1, -1, -1, 1, -1};
public:
    void BFS(vector<vector<char>>& board, int sx, int sy){
        queue<pair<int, int>> que;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        que.push({sx, sy});
        visited[sx][sy] = true;

        while(que.size() != 0){
            auto pos = que.front();que.pop();
            int x = pos.first, y = pos.second;
            int cnt_m = 0;
            for(int i = 0; i < 8; ++i){
                int next_x = x + dir[i][0];
                int next_y = y + dir[i][1];
                if (next_x < 0 || next_x >= board.size() || next_y < 0 || next_y >= board[0].size()) continue;
                if(board[next_x][next_y] == 'M'){
                    cnt_m += 1;
                }
            }

            if(cnt_m > 0){
                board[x][y] = cnt_m + '0';
            }
            else{
                board[x][y] = 'B';
                for(int i = 0; i < 8; ++i){
                    int next_x = x + dir[i][0];
                    int next_y = y + dir[i][1];
                    if (next_x < 0 || next_x >= board.size() || next_y < 0 || next_y >= board[0].size() || board[next_x][next_y] != 'E' || visited[next_x][next_y] == true) continue;
                    que.push({next_x, next_y});
                    visited[next_x][next_y] = true;
                }
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, 
    vector<int>& click) {
        // 第一个实例，雷上面那个不会变，是因为在BFS中，如果cnt_m > 0
        // 就会直接变成周围雷的数量，不会把周围可以访问的点放进queue里面
        // 所以雷顶上的那个小块不会进入队列，不会被访问，就会一直维持'E'的状态
        int x = click[0], y = click[1];
        if(board[x][y] == 'M'){
            board[x][y] = 'X';
        }
        else{
            BFS(board, x, y);
        }
        return board;
    }
};
// @lc code=end

