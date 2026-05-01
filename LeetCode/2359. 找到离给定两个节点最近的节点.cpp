class Solution {
public:
    // 题目输入是一个基环树
    // 但是这道题可以有别的方法做，比如下面这种方法
    int closestMeetingNode(vector<int>& edges, int x, int y) {
        int n = edges.size();
        int ans = n;
        vector<int8_t> vis_x(n), vis_y(n);

        while (!vis_x[x] || !vis_y[y]) { // x 或 y 没有访问过
            vis_x[x] = vis_y[y] = true; // 标记访问过

            if (vis_y[x]) { // 我吹过你吹过的晚风
                ans = x;
            }
            if (vis_x[y]) {
                ans = min(ans, y); // 如果有多个答案，返回最小的节点编号
            }
            if (ans < n) {
                return ans;
            }

            if (edges[x] >= 0) {
                x = edges[x]; // 继续走
            }
            if (edges[y] >= 0) {
                y = edges[y]; // 继续走
            }
        }

        return -1;
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/find-closest-node-to-given-two-nodes/solutions/1710829/ji-suan-dao-mei-ge-dian-de-ju-chi-python-gr2u/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。