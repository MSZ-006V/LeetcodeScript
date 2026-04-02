// 直接使用两次拓扑排序，分别得到行和列的顺序，然后根据行的顺序和列的顺序构造矩阵
class Solution {
    vector<int> topo_sort(int k, vector<vector<int>> &edges) {
        vector<vector<int>> g(k);
        vector<int> in_deg(k);
        for (auto &e : edges) {
            int x = e[0] - 1, y = e[1] - 1; // 顶点编号从 0 开始，方便计算
            g[x].push_back(y);
            ++in_deg[y];
        }

        vector<int> order;
        queue<int> q;
        for (int i = 0; i < k; ++i)
            if (in_deg[i] == 0)
                q.push(i);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            order.push_back(x);
            for (int y : g[x])
                if (--in_deg[y] == 0)
                    q.push(y);
        }
        return order;
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions) {
        auto row = topo_sort(k, rowConditions), col = topo_sort(k, colConditions);
        if (row.size() < k || col.size() < k) return {};
        vector<int> pos(k);
        for (int i = 0; i < k; ++i)
            pos[col[i]] = i;
        vector<vector<int>> ans(k, vector<int>(k));
        for (int i = 0; i < k; ++i)
            ans[i][pos[row[i]]] = row[i] + 1;
        return ans;
    }
};

