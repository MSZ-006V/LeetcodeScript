/*
 * @lc app=leetcode id=2080 lang=cpp
 *
 * [2080] Range Frequency Queries
 */

// @lc code=start
class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> ht;
    RangeFreqQuery(vector<int>& arr) {
        for(int i = 0; i < arr.size(); ++i){
            ht[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        vector<int>& arr = ht[value]; // 这一句一定要用引用取值，不然就会超时
        auto wleft = ranges::lower_bound(arr.begin(), arr.end(), left);
        auto wright = ranges::upper_bound(arr.begin(), arr.end(), right);
        return wright - wleft;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
// @lc code=end

