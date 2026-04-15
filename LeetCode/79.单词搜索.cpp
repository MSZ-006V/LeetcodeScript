/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int n;
    int m;
    bool search(vector<vector<char>>& board, vector<vector<bool>>& visited, 
    string word, int index, int x, int y){
        bool result = false;

        if(index == word.size())
            return true;

        for(int i = 0; i < 4; ++i){
            int next_x = x + dir[i][0];
            int next_y = y + dir[i][1];
            if(next_x < 0 || next_y < 0 || next_x >= n || next_y >= m){
                continue;
            }
            if(visited[next_x][next_y] == false && word[index] == board[next_x][next_y]){
                visited[next_x][next_y] = true;
                result |= search(board, visited, word, index + 1, next_x, next_y);
                visited[next_x][next_y] = false; 
                // 注意这一步要回溯，不然走过的路径的visited被设置为true，不能继续找了
            }
        }
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        char start = word[0];
        n = board.size();
        m = board[0].size();
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(board[i][j] == start){
                    vector<vector<bool>> visited(n, vector<bool>(m, false));
                    visited[i][j] = true;
                    if(search(board, visited, word, 1, i, j)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end

class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    int n, m;

    bool dfs(vector<vector<char>>& board, string& word, int index, int x, int y) {
        // 终止条件：路径长度等于单词长度，说明找全了
        if (index == word.size()) return true;

        // 保存当前字符并标记为已访问（通过修改原数组省去 visited 空间）
        char temp = board[x][y];
        board[x][y] = '#'; 

        for (auto& d : dir) {
            int nx = x + d[0];
            int ny = y + d[1];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == word[index]) {
                if (dfs(board, word, index + 1, nx, ny)) return true;
            }
        }

        // --- 关键一步：回溯 ---
        board[x][y] = temp; 
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // 起点匹配
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, 1, i, j)) return true;
                }
            }
        }
        return false;
    }
};
