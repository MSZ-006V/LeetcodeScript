class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        // tc O(n^2), sc O(k)
        int cnt1[3]{}, cnt2[3]{};
        // cnt1[3] 用来统计 属于 "Y" 区域 的格子中，0、1、2 分别出现的次数
        // cnt2[3] 用来统计 不属于 "Y" 区域 的格子中，0、1、2 分别出现的次数
        int n = grid.size();
        int m = n / 2;

        // 上半部分（0 到 m-1 行，即 Y 的两根分叉）
        for (int i = 0; i < m; i++) {
            cnt1[grid[i][i]]++;
            cnt1[grid[i][n - 1 - i]]++;
            for (int j = 0; j < n; j++) {
                if (j != i && j != n - 1 - i) {
                    cnt2[grid[i][j]]++;
                }
            }
        }
        // 下半部分（m 到 n-1 行，即 Y 的垂直主干，包含中心点）
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
                    // 假设把 "Y" 全变成数字 i，"非 Y" 全变成数字 j，这里统计的就是修改代价
                    // 这里使用逆向思维，原本统计的是最少变动的，这里统计的是最大不变的
                    // 最后使用总数 n * n - 最大不变的，就是最小变的
                }
            }
        }

        return n * n - max_not_change;
    }
};