class Solution {
public:
    int m, n;
    vector<vector<int>> grid;
    vector<vector<bool>> vis;

    vector<pair<int,int>> path;

    vector<pair<int,int>> normalize(const vector<pair<int,int>>& v) {
        // 需要进行归一化，即把所有的点都移动到左上角
        // 比如对应（3，4），（4，5），（5，6）这样的点，归一化之后就是（0，0），（1，1），（2，2）
        // 这样就可以保证不同的岛屿类型有不同的编码
        int minx = INT_MAX, miny = INT_MAX;
        for (auto &p : v) {
            minx = min(minx, p.first);
            miny = min(miny, p.second);
        }
        vector<pair<int,int>> res;
        for (auto &p : v) res.push_back({p.first - minx, p.second - miny});
        sort(res.begin(), res.end());
        return res;
    }

    // 生成 8 种变换
    vector<vector<pair<int,int>>> transform(const vector<pair<int,int>>& shape) {
        vector<vector<pair<int,int>>> forms(8);

        for (auto &p : shape) {
            int x = p.first, y = p.second;

            // 8 种变换
            // 包括旋转和翻转，旋转有4种，翻转有2种，一共是8种
            forms[0].push_back({ x,  y});
            forms[1].push_back({ x, -y});
            forms[2].push_back({-x,  y});
            forms[3].push_back({-x, -y});
            forms[4].push_back({ y,  x});
            forms[5].push_back({ y, -x});
            forms[6].push_back({-y,  x});
            forms[7].push_back({-y, -x});
        }

        // 每个形式进行 normalize 排序
        for (auto &f : forms) f = normalize(f);

        return forms;
    }

    void dfs(int x, int y, int ox, int oy) {
        vis[x][y] = true;
        path.push_back({x - ox, y - oy});

        static int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for (auto &d : dirs) {
            int nx = x + d[0], ny = y + d[1];
            if (nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1 && !vis[nx][ny]) {
                dfs(nx, ny, ox, oy);
            }
        }
    }

    string canonical(const vector<pair<int,int>>& shape) {
        auto forms = transform(shape);

        // 找最小的那个形式作为 canonical
        sort(forms.begin(), forms.end());
        const auto &best = forms[0];

        // 序列化为字符串（可以直接序列化 pair）
        string s;
        for (auto &p : best) {
            s += to_string(p.first) + "," + to_string(p.second) + ";";
        }
        return s;
    }

    int numDistinctIslands2(vector<vector<int>>& g) {
        grid = g;
        m = grid.size();
        n = grid[0].size();
        vis.assign(m, vector<bool>(n, false));

        unordered_set<string> st;

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    path.clear();
                    dfs(i, j, i, j);
                    string c = canonical(path);
                    st.insert(c);
                }
            }
        }
        return st.size();
    }
};
