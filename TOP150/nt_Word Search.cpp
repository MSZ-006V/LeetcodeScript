class Solution {
public:
    int n;
    int m;
    bool isFind;
    int dir[4][2] = {0, 1, 0, -1, -1, 0, 1, 0};
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int index, string word, int x, int y){
        if(index == word.size()){
            isFind = true;
            return;
        }

        for(int i = 0; i < 4; ++i){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m || board[nx][ny] != word[index] || visited[nx][ny]) continue;

            visited[nx][ny] = true;
            dfs(board, visited, index + 1, word, nx, ny);
            visited[nx][ny] = false;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        isFind = false;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(isFind) return isFind;
                if(board[i][j] == word[0]){
                    visited[i][j] = true;
                    dfs(board, visited, 1, word, i, j);
                    visited[i][j] = false;
                }
            }
        }

        return isFind;
    }
};
