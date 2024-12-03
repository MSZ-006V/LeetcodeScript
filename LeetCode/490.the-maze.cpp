/*
 * @lc app=leetcode id=490 lang=cpp
 *
 * [490] The Maze
 */

// @lc code=start
struct Node {
    int x, y, val;
    Node(int _x, int _y, int _val): x(_x), y(_y), val(_val) {}
};

class Solution {
private:
    const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int n, m;

public:
    Node* findFinalPos(vector<vector<int>>& maze, int x, int y, int i) {
        int cnt = 0;
        while (x >= 0 && y >= 0 && x < n && y < m && maze[x][y] == 0) {
            x += dir[i][0];
            y += dir[i][1];
            cnt++;
        }
        x -= dir[i][0];
        y -= dir[i][1];
        cnt--;  // 回退后的步数

        return new Node(x, y, cnt);
    }

    int hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        n = maze.size();
        m = maze[0].size();

        // 距离数组，记录到每个点的最短距离
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[start[0]][start[1]] = 0;

        // 优先队列，优先弹出路径长度最短的节点（Dijkstra 的思想）
        auto cmp = [](Node* a, Node* b) { return a->val > b->val; };
        priority_queue<Node*, vector<Node*>, decltype(cmp)> pq(cmp);

        pq.push(new Node(start[0], start[1], 0));

        while (!pq.empty()) {
            Node* cur = pq.top(); pq.pop();

            // 如果当前节点已经到达目标点
            if (cur->x == destination[0] && cur->y == destination[1]) {
                return true;
            }

            // 遍历四个方向
            for (int i = 0; i < 4; ++i) {
                Node* nextNode = findFinalPos(maze, cur->x, cur->y, i);
                int nx = nextNode->x, ny = nextNode->y, newDist = cur->val + nextNode->val;

                // 如果新的路径比已有路径更短，更新并入队
                if (newDist < dist[nx][ny]) {
                    dist[nx][ny] = newDist;
                    pq.push(new Node(nx, ny, newDist));
                }
            }
        }

        return false; // 如果无法到达目标点
    }
};
// @lc code=end

