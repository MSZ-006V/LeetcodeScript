/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */

// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // 差分数组经典题目, 可以参考题解
        // https://leetcode.cn/problems/car-pooling/?source=vscode
        // 题解讲的很好
        int to_max = 0;
        for(auto& trip:trips){
            if(trip[2] > to_max) to_max = trip[2];
        }
        vector<int> diff = vector<int>(to_max + 1, 0);
        // 原来的diff数组全部都是0
        for(auto& trip:trips){
            int num_passengers = trip[0], from = trip[1], to = trip[2];
            diff[from] += num_passengers; // 在from的位置加上乘客数量
            diff[to] -= num_passengers; // 在to的位置减去乘客数量
        }
        // 基于差分数组的性质，从左往右依次累加，就可以还原出整个数组
        // 如果diff的最大值大于capacity,就代表车做不下了，就返回false即可
        int sum = 0;
        for(auto val:diff){
            sum += val;
            if(sum > capacity){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> cars(1001, 0);
        for(auto t : trips){
            int p = t[0];
            cars[t[1]] += p;
            cars[t[2]] -= p;
        }

        int cur_p = 0;
        for(int i = 0; i < 1001; ++i){
            cur_p += cars[i];
            if(cur_p > capacity) return false;
        }

        return true;
    }
};