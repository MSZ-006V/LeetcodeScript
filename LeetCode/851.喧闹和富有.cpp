class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {

        int n = quiet.size();
        vector<vector<int>> es(n);
        vector<int> in_deg(n);
        for (auto &r : richer) {
            es[r[0]].emplace_back(r[1]);
            ++in_deg[r[1]];
        }

        vector<int> ans(n, 0);
        iota(ans.begin(), ans.end(), 0); // 初始化每个人的答案为自己, 等差数列，从0开始

        queue<int> que;
        for (int i = 0; i < n; ++i) {
            if (in_deg[i] == 0) {
                que.push(i);
            }
        }

        while (!que.empty()) {
            int x = que.front(); que.pop();
            for (int y : es[x]) {
                // x 比 y 更有钱
                if (quiet[ans[x]] < quiet[ans[y]]) {
                    ans[y] = ans[x]; // 更新 x 的邻居的答案
                }
                if (--in_deg[y] == 0) {
                    que.push(y);
                }
            }
        }
        return ans;
    }
};
