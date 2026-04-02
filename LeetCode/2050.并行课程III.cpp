class Solution {
public:
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time) {
        // 题目类型：拓扑DP
        // tc O(n + m), sc O(n + m)，其中 m 是关系的数量
        vector<vector<int>> g(n);
        vector<int> deg(n);
        for (auto &r: relations) {
            int x = r[0] - 1, y = r[1] - 1;
            g[x].push_back(y); // 建图
            deg[y]++; // 可以理解为 y 的先修课的个数
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (deg[i] == 0) // 没有先修课
                q.push(i);
        vector<int> f(n);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            // x 出队，意味着 x 的所有先修课都上完了
            f[x] += time[x]; // 加上当前课程的时间，就得到了最终的 f[x]
            for (int y: g[x]) { // 遍历 x 的邻居 y
                f[y] = max(f[y], f[x]); // 更新 f[y] 的所有先修课程耗时的最大值
                if (--deg[y] == 0) // y 的先修课已上完
                    q.push(y);
            }
        }
        return *max_element(f.begin(), f.end());
    }
};
