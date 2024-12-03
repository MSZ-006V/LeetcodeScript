/*
 * @lc app=leetcode id=505 lang=cpp
 *
 * [505] The Maze II
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

    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
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
                return cur->val;
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

        return -1; // 如果无法到达目标点
    }
};

// 下面这版是错误的代码，上面是正确的GPT代码

// struct Node {
//     int x, y, val;
//     Node(int _x, int _y, int _val): x(_x), y(_y), val(_val) {}
// };

// class Solution {
// private:
//     const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
//     int n, m;

// public:
//     Node* findFinalPos(vector<vector<int>>& maze, int x, int y, int i) {
//         int cnt = 0;
//         while (x >= 0 && y >= 0 && x < n && y < m && maze[x][y] == 0) {
//             x += dir[i][0];
//             y += dir[i][1];
//             cnt++;
//         }
//         x -= dir[i][0];
//         y -= dir[i][1];
//         --cnt;
        
//         return new Node(x, y, cnt);
//     }

//     int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
//         n = maze.size();
//         m = maze[0].size();
//         vector<vector<bool>> visited(n, vector<bool>(m, false));
//         queue<Node*> que;
//         Node* node = new Node(start[0], start[1], 0);
//         que.push(node);
//         visited[start[0]][start[1]] = true;

//         while (!que.empty()) {
//             Node* cur_n = que.front(); que.pop();
//             for (int i = 0; i < 4; ++i) {
//                 Node* nextNode = findFinalPos(maze, cur_n->x, cur_n->y, i);

//                 if (nextNode->x == destination[0] && nextNode->y == destination[1]) {
//                     return cur_n->val + nextNode->val; // 提前返回结果
//                 }

//                 if (nextNode->x >= 0 && nextNode->x < n && nextNode->y >= 0 && nextNode->y < m &&
//                     maze[nextNode->x][nextNode->y] == 0 && !visited[nextNode->x][nextNode->y]) {

//                     visited[nextNode->x][nextNode->y] = true;
//                     nextNode->val += cur_n->val;
//                     que.push(nextNode);
//                 }
//             }
//         }

//         return -1;
//     }
// };

// @lc code=end

