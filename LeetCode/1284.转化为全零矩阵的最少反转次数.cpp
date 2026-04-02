// BFS的具体步骤:
// 1.入队:把初始矩阵编码后的整数x_start 丢进队列，标记visited。
// 2.层级遍历:每次从队列里取出一个状态(代表当前的矩阵长相)。
// 3.尝试所有“邻居”:
// 矩阵有m*n个位置。你在每一个位置(i,j)都试着”点一下”。
// "点一下"会触发convert 函数:改变(i,j)及其上下左右共5个格子的状态(0变1,1变0)
// 得到一个新状态 x_cur
// 4.判断结果:
// 如果x_cur == 0，恭喜你，找到了!返回当前的step。
// 如果没见过这个状态，丢进队列继续搜。
// 关键细节:搜完一个位置后，要再调用一次 convert(即代码里的convert(status,m，n，i，j))
// 这叫恢复现场，以便尝试点击下一个位置。

// 3.时间复杂度分析
// 这个解法之所以能过，是因为搜索空间其实很小:
// 状态总数:矩阵最多9个格。每个格2种状态(0或1)，总状态数为2=512
// 每个状态的转移:尝试点击m*n个位置，每个位置修改5个格子
// 总复杂度:O(2^mn (m.n)2)
// 对于3X3的矩阵，这个数字非常小，BFS瞬间就能跑完

class Solution {
private:
    static constexpr int dirs[5][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {0, 0}};

public:
    int encode(const vector<vector<int>>& mat, int m, int n) {
        int x = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                x = x * 2 + mat[i][j];
            }
        }
        return x;
    }

    vector<vector<int>> decode(int x, int m, int n) {
        vector<vector<int>> mat(m, vector<int>(n));
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                mat[i][j] = x & 1;
                x >>= 1;
            }
        }
        return mat;
    }

    void convert(vector<vector<int>>& mat, int m, int n, int i, int j) {
        for (int k = 0; k < 5; ++k) {
            int i0 = i + dirs[k][0], j0 = j + dirs[k][1];
            if (i0 >= 0 && i0 < m && j0 >= 0 && j0 < n) {
                mat[i0][j0] ^= 1;
            }
        }
    }

    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int x_start = encode(mat, m, n), step = 0;
        if (x_start == 0) {
            return step;
        }

        unordered_set<int> visited;
        queue<int> q;
        visited.insert(x_start);
        q.push(x_start);

        while (!q.empty()) {
            ++step;
            int k = q.size();
            for (int _ = 0; _ < k; ++_) {
                vector<vector<int>> status = decode(q.front(), m, n);
                q.pop();
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        convert(status, m, n, i, j);
                        int x_cur = encode(status, m, n);
                        if (x_cur == 0) {
                            return step;
                        }
                        if (!visited.count(x_cur)) {
                            visited.insert(x_cur);
                            q.push(x_cur);
                        }
                        convert(status, m, n, i, j);
                    }
                }
            }
        }

        return -1;
    }
};

// 