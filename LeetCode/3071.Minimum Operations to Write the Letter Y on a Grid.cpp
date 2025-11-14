class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        // tc O(n^2), sc O(k)
        int cnt1[3]{}, cnt2[3]{};
        int n = grid.size();
        int m = n / 2;

        for (int i = 0; i < m; i++) {
            cnt1[grid[i][i]]++;
            cnt1[grid[i][n - 1 - i]]++;
            for (int j = 0; j < n; j++) {
                if (j != i && j != n - 1 - i) {
                    cnt2[grid[i][j]]++;
                }
            }
        }
        for (int i = m; i < n; i++) {
            cnt1[grid[i][m]]++;
            for (int j = 0; j < n; j++) {
                if (j != m) {
                    cnt2[grid[i][j]]++;
                }
            }
        }

        int max_not_change = 0;
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                if(i != j){
                    max_not_change = max(max_not_change, cnt1[i] + cnt2[j]);
                    // 这里使用逆向思维，原本统计的是最少变动的，这里统计的是最大不变的
                    // 最后使用总数 n * n - 最大不变的，就是最小变的
                }
            }
        }

        return n * n - max_not_change;
    }
};