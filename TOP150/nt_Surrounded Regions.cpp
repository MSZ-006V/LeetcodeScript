class Solution {
public:
    int n;
    int m;
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        vector<vector<bool>> turns(n, vector<bool>(m, true)); // 需要转的就是ture
        vector<vector<bool>> visited(n, vector<bool>(m, false)); 

        for(int i = 0; i < n; ++i){
            if(board[i][0] == 'O') dfs(i, 0, board, visited, turns);
            if(board[i][m - 1] == 'O') dfs(i, m - 1, board, visited, turns);
        }

        for(int j = 0; j < m; ++j){
            if(board[0][j] == 'O') dfs(0, j, board, visited, turns);
            if(board[n - 1][j] == 'O') dfs(n - 1, j, board, visited, turns);
        }


        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(turns[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(int x, int y, vector<vector<char>>& board, vector<vector<bool>>& visited, vector<vector<bool>>& turns){
        turns[x][y] = false;
        visited[x][y] = true;
        for(int i = 0; i < 4; ++i){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && 
            !visited[nx][ny] && board[nx][ny] == 'O'){
                dfs(nx, ny, board, visited, turns);
            }
        }
    }
};
