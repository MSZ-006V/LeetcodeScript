class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        function<void(int,int)> dfs = [&](int r, int c){
            if (r < 0 || c < 0 || r >= n || c >= m) return;

            if (board[r][c] != 'O') return;

            board[r][c] = '#';  // 标记为不被包围
            
            for (auto &d : dirs)
                dfs(r + d[0], c + d[1]);
        };

        // 1. 从四条边界的 O 逆向 DFS，把所有“不被包围”的标记出来
        for (int i = 0; i < n; i++) {
            dfs(i, 0);
            dfs(i, m - 1);
        }
        for (int j = 0; j < m; j++) {
            dfs(0, j);
            dfs(n - 1, j);
        }

        // 2. 把剩下的 O（没标记成 # 的）变成 X
        //    把 # 还原成 O
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};
