class Solution {
public:
    // 区间DP的解法，时间复杂度 O(n^3)，空间复杂度 O(n^2)
    // 太复杂了
    int mergeStones(vector<int> &stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1)) // 无法合并成一堆
            return -1;

        int s[n + 1];
        s[0] = 0;
        for (int i = 0; i < n; i++)
            s[i + 1] = s[i] + stones[i]; // 前缀和

        int memo[n][n][k + 1];
        memset(memo, -1, sizeof(memo)); // -1 表示还没有计算过
        function<int(int, int, int)> dfs = [&](int i, int j, int p) -> int {
            int &res = memo[i][j][p]; // 注意这里是引用，下面会直接修改 memo[i][j][p]
            if (res != -1) return res;
            if (p == 1) // 合并成一堆
                return res = i == j ? 0 : dfs(i, j, k) + s[j + 1] - s[i];
            res = INT_MAX;
            for (int m = i; m < j; m += k - 1) // 枚举哪些石头堆合并成第一堆
                res = min(res, dfs(i, m, 1) + dfs(m + 1, j, p - 1));
            return res;
        };
        return dfs(0, n - 1, 1);
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/minimum-cost-to-merge-stones/solutions/2207235/tu-jie-qu-jian-dpzhuang-tai-she-ji-yu-yo-ppv0/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。