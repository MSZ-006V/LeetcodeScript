/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 这题很简单，首先使用哈希表统计，然后自定义优先队列排序，从小到大排序
        // 然后把哈希表里面全部元素插入队列，多了就把多余弹出，然后全部弄进一个vector里面就行
        unordered_map<int, int> ht;
        for(int x : nums){
            ht[x]++;
        }
        
        auto cmp = [](pair<int, int>& a, pair<int, int>& b){
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pque(cmp);
        for(auto e : ht){
            pque.push(e);
            if(pque.size() > k) pque.pop();
        }

        vector<int> result;
        while(pque.size() != 0){
            result.push_back(pque.top().first); pque.pop();
        }
        reverse(result.begin(), result.end());
        return result;
        
    }
};
// @lc code=end

