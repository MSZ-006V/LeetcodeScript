class Solution {
public:
    // BFS 模拟 + 优化
    // tc: O(query_row^2), sc: O(query_row)
    // 处理第一层到第二层，从 (0,0) 溢出的香槟流到 (1,0) 和 (1,1)。设溢出的香槟量为 x，那么 (1,0) 和 (1,1) 的香槟量都增加 x/2
    // 处理第二层到第三层，从 (1,0) 溢出的香槟流到 (2,0) 和 (2,1)，从 (1,1) 溢出的香槟流到 (2,1) 和 (2,2)。
    // 依此类推。一般地，从 (i,j) 溢出的香槟流到 (i+1,j) 和 (i+1,j+1)。设溢出的香槟量为 x，那么下一层的 j 和 j+1 的香槟量都增加 x/2​。
    // 用一个数组保存下一层每个玻璃杯的香槟量。
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> cur = {1.0 * poured};
        for (int i = 1; i <= query_row; ++i) {
            vector<double> next(i + 1);
            for (int j = 0; j < cur.size(); ++j) {
                double x = cur[j] - 1;
                if (x > 0) {
                    next[j] += x / 2;
                    next[j + 1] += x/ 2;
                }
            }
            cur = move(next);
        }

        return min(cur[query_glass], 1.0);
    }
};