/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */

// @lc code=start
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        queue<int> que;
        que.push(0);
        

        while(!que.empty()){
            int cur = que.front();que.pop();
            visited[cur] = true;
            vector<int> keys = rooms[cur];
            for(int i = 0; i < keys.size(); ++i){
                cout << keys[i] << ' ';
                if(visited[keys[i]] == false){
                    que.push(keys[i]);
                }
            }
        }

        for(int i = 0; i < n; ++i){
            if(visited[i] == false){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

