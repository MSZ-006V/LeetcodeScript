/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
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

