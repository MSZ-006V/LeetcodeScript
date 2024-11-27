/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 */

// @lc code=start
class Solution {
public:
    拼火柴的游戏，必须使用所有的火柴
    bool dfs(vector<int>& ms, vector<int>& edges, int length, int index){
        if(index == ms.size()){
            return true;
        }

        for(int i = 0; i < edges.size(); ++i){
            edges[i] += ms[index];
            // 实例[1,1,2,2,2]
            if(edges[i] <= length && dfs(ms, edges, length, index + 1)){
                return true;
            }
            edges[i] -= ms[index];
        }

        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(sum % 4 != 0 || matchsticks.size() < 4) return false;
        int length = sum / 4;
        vector<int> edges(4);
        
        sort(matchsticks.rbegin(), matchsticks.rend());

        return dfs(matchsticks, edges, length, 0);
    }
};
// @lc code=end

