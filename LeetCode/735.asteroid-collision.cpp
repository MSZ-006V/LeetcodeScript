/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

// @lc code=start
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i = 0; i < asteroids.size(); ++i){
            // 每个小行星初始的时候alive都是true
            bool alive = true;
            // 一共有三种情况需要判断，比如10, -5; 2, -5; -5, -5; 分别对应小行星是否被销毁和是否需要从栈中弹出元素
            while(alive && asteroids[i] < 0 && st.size() != 0 && st.top() > 0){
                alive = st.top() < -asteroids[i]; // 如果<的话，alive是true，否则是false
                if(st.top() <= -asteroids[i]) st.pop(); // 如果<=，需要从栈中弹出一个元素
                // 同时这个过程需要使用while循环
            }
            if(alive) st.push(asteroids[i]); // 对应2，-5的情况，小行星2会被销毁，-5依然存活，需要把仍然alive的小行星压入栈
        }
        vector<int> result;
        while(!st.empty()){
            result.insert(result.begin(), st.top()); // 头插,insert(nums.begin(), value);
            st.pop();
        }
        return result;
    }
};
// @lc code=end

