class Solution
{
public:
    // 采用leetcode 785 判断二分图的模版方式
    bool dfs(vector<vector<int>> &graph, vector<int> &colors, int x, int color)
    {
        colors[x] = color;
        for (auto y : graph[x])
        {
            if (colors[y] == color ||
                (colors[y] == 0 && !dfs(graph, colors, y, -color)) // !dfs(graph, colors, y, -color) 代表如果没有染色成功，返回false，这里就会变成true，从而继续传递false
            )
            {
                return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        vector<int> colors(graph.size());
        for (int i = 0; i < graph.size(); ++i)
        {
            if (colors[i] == 0 && !dfs(graph, colors, i, 1))
            {
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        vector<vector<int>> graph(n);
        for (auto d : dislikes)
        {
            int x = d[0] - 1, y = d[1] - 1;
            // 要注意这个是无向图，应该双向添加边
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        return isBipartite(graph);
    }
};

// 并查集 + 偏移分组
class Solution {
public:
    vector<int> parent;
    int find(int u) {
        if (parent[u] == u) return u;
        else return parent[u] = find(parent[u]);
    }

    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if(u == v) return;
        parent[v] = u;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        parent.resize(2 * n + 1);
        for (int i = 1; i < 2 * n + 1; ++i) {
            parent[i] = i;
        }

        for (auto d : dislikes) {
            int u = d[0];
            int v = d[1];

            if (find(u) == find(v)) {
                return false;
            }
            join(u, v + n);
            join(v, u + n);
        }

        return true;
    }
};