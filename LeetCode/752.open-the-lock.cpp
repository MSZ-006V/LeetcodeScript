/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */

// @lc code=start
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // 双向BFS，创建两个队列，两个哈希表进行搜索，这样子能够减少搜索空间
        // 双向BFS的搜索空间通常只有普通BFS搜索空间的几千分之一
        string s = "0000";
        if(s == target) return 0;
        unordered_set<string> st(deadends.begin(), deadends.end());
        if(st.count(s)) return -1;
        
        return bfs(st, s, target);
    }
    int bfs(unordered_set<string>& st, string s, string t){
        queue<string> que1, que2;
        unordered_map<string, int> ht1, ht2;
        que1.push(s); ht1[s] = 0;
        que2.push(t); ht2[t] = 0;

        while(que1.size() && que2.size()){
            int t = -1;
            if(que1.size() <= que2.size()){
                t = update(st, que1, ht1, ht2);
            }
            else{
                t = update(st, que2, ht2, ht1);
            }
            if(t != -1) return t;
        }
        return -1;
    }
    int update(unordered_set<string>& st, queue<string>& que,
    unordered_map<string, int>& ht1, unordered_map<string, int>& ht2){
        int k = que.size(); // 记录当前队列长度，这一步很关键，保证了while循环一定会停止
        // 如果写成while(que.size() > 0), 就不是双向BFS而是单向了
        while(k-- > 0){
            string t = que.front();que.pop();
            int step = ht1[t];

            for(int i = 0; i < 4; ++i){
                for(int j = -1; j <= 1; ++j){
                    if(j == 0) continue;
                    int origin = t[i] - '0';
                    int next = (origin + j) % 10;

                    if(next == -1) next = 9;

                    string copyt = t;
                    copyt[i] = '0' + next;

                    if(st.count(copyt) or ht1.count(copyt)) continue;
                    if(ht2.count(copyt)){
                        return step + 1 + ht2[copyt];
                    }
                    else{
                        que.push(copyt);
                        ht1[copyt] = step + 1;
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end

