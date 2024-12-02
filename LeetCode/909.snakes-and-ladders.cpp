/*
 * @lc app=leetcode id=909 lang=cpp
 *
 * [909] Snakes and Ladders
 */

// @lc code=start
class Solution {
public:
    pair<int, int> getNext(int index, int n){
        int r = (index - 1) / n;
        int x = 0;
        int y = 0;
        // 假设访问的点的序号是index，那么行的实际标号就是(index - 1) / n，设为r
        // 当r是偶数的时候，序号是从左往右递增的
        // 所以列的实际标号是(index - 1) % n
        // 当r是奇数的时候，序号是从右往左递增的
        // 所以列的实际标号是n - 1 - [(index - 1) % n]
        if(r % 2 == 0){
            x = n - 1 - r;
            y = (index - 1) % n;
        }
        else{
            x = n - 1 - r;
            y = n - 1 - ((index - 1) % n);
        }
        return make_pair(x, y);
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        queue<pair<int, int>> que;
        int n = board.size();
        vector<bool> visited(n * n + 1, false);
        que.push(make_pair(1, 0));
        
        while(!que.empty()){
            auto cur = que.front(); que.pop();
            for(int i = 1; i <= 6; ++i){
                int next_index = cur.first + i;
                if(next_index > n * n) break; // 超出边界

                auto next_point = getNext(next_index, n); // 得到下一步的行列
                if(board[next_point.first][next_point.second] > 0){ // 存在蛇或梯子
                    next_index = board[next_point.first][next_point.second]; // 则下一个标号是经过蛇或者梯子的结果
                }
                if(next_index == n * n){
                    return cur.second + 1; // 到达终点直接返回
                }
                if(visited[next_index] == false){ // 防止重复访问
                    visited[next_index] = true;
                    que.push(make_pair(next_index, cur.second + 1));
                }
            }
        }
        return -1;
    }
};
// @lc code=end

