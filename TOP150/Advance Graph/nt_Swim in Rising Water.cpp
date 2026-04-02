class Solution {
public:
    // leetcode778，二分查找+DFS
    int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    int swimInWater(vector<vector<int>>& grid) {
        // tc O(n^2 log(n)), sc O(n^2)
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, -1));

        auto check = [&](int mx) -> bool {
            auto dfs = [&](this auto &&dfs, int i, int j) -> bool {
                if(i == n - 1 && j == n - 1) return true;

                visited[i][j] = mx;
                for(auto &[dx, dy] : dir){
                    int x = i + dx, y = j + dy;
                    if(x >= 0 && y >= 0 && x < n && y < n && grid[x][y] <= mx && visited[x][y] != mx && dfs(x, y)){
                        return true;
                    }
                }

                return false;
            };

            return dfs(0, 0);
        };

        int left = max(grid[0][0], grid[n - 1][n - 1]), right = n * n - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(check(mid)){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return left;
    }
};

// priority queue + bfs
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // tc O(n^2 log(n))), sc O(n^2)
        int n = grid.size();
        // 最小堆：存放 {当前格子的高度, x坐标, y坐标}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // 1. 起点入队
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        
        int res = 0; // 记录一路上遇到的最高水位

        // 2. BFS 式扩展，但用的是 Priority Queue
        while(!pq.empty()){
            auto [h, x, y] = pq.top();
            pq.pop();
            
            // 水位必须漫过当前这块石头，所以水位至少得是历史遇到的最高值
            res = max(res, h); 
            
            // 只要摸到了终点，立刻返回当前的历史最高水位！
            if(x == n - 1 && y == n - 1) return res;

            // 往四周蔓延
            for(auto& d : dirs){
                int nx = x + d[0], ny = y + d[1];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    pq.push({grid[nx][ny], nx, ny});
                }
            }
        }
        return -1;
    }
};

// union find + kruskal
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // tc O(n^2 log(n)), sc O(n^2)
        int n = grid.size();
        
        // 1. 抽取所有格子并按高度排序
        // 存放格式：{高度, x坐标, y坐标}
        vector<tuple<int, int, int>> cells;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cells.push_back({grid[i][j], i, j});
            }
        }
        // 按高度从小到大排序 (这就体现了 Kruskal 贪心找最小边的思想)
        sort(cells.begin(), cells.end()); 
        
        // 2. 初始化你的满分 DSU 模板！大小为 N*N
        DSU dsu(n * n); 
        
        // 记录哪些格子已经被"解锁"了
        vector<vector<bool>> unlocked(n, vector<bool>(n, false));
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // 3. 开始从小到大放水
        for(auto& [h, x, y] : cells) {
            unlocked[x][y] = true; // 解锁当前格子
            
            // 尝试和四周已经解锁的邻居合并
            for(auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && unlocked[nx][ny]) {
                    // 把 2D 坐标压平为 1D 传给 DSU
                    dsu.join(x * n + y, nx * n + ny);
                }
            }
            
            // 每解锁并合并完一次，查一下起点 (0) 和终点 (n*n-1) 是否连通了？
            if(dsu.isSame(0, n * n - 1)) {
                return h; // 连通的瞬间，这个高度就是答案！
            }
        }
        
        return -1;
    }
};