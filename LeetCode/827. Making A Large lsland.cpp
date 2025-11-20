class Solution {
public:
    int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> area;

        // c++20新特性，允许lambda递归
        auto dfs = [&](this auto&& dfs, int x, int y) -> int{
            grid[x][y] = area.size() + 2; // 原grid中只有0，1，用这种巧妙地方法来对岛屿进行标记
            int size = 1;
            for(int i = 0; i < 4; ++i){
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if(nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 1){
                    size += dfs(nx, ny);
                }
            }

            return size;
        };

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    area.push_back(dfs(i, j));
                }
            }
        }

        // for(auto i : area){
        //     cout << i << ' ';
        // }

        if(area.size() == 0) return 1;
        int ans = 0;
        unordered_set<int> islands;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 0){
                    islands.clear();
                    int new_size = 1;
                    for(int k = 0; k < 4; ++k){
                        int nx = i + dir[k][0];
                        int ny = j + dir[k][1];
                        // islands.insert返回一个pair，second表示是否插入成功
                        // 如果second是false，就代表插入过了，就不需要再加一次了
                        // 在访问area时，grid[nx][ny] - 2是因为之前标记岛屿时是从2开始的
                        if(nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] != 0 && islands.insert(grid[nx][ny]).second){
                            new_size += area[grid[nx][ny] - 2];
                        }
                    }
                    ans = max(ans, new_size);
                }
            }
        }

        return ans == 0? n * n:ans;
    }
};