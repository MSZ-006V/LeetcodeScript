/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start
class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> ht;
    // 根据键和一个pair来存储
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        ht[key].push_back({timestamp, value});
        // 直接插入即可
    }
    
    string get(string key, int timestamp) {
        auto &pairs = ht[key];
        // 使用引用可以加速
        pair<int, string> p = {timestamp, string({127})};
        // string({127})的目的是创建一个最大的字符串，这样子可以找到pairs里面最大的一个
        // 然后再减一就是对应key里面最大的一个了，所以使用upper_bound来找大于的

        auto i = ranges::upper_bound(pairs.begin(), pairs.end(), p);
        if(i != pairs.begin()){ // 因为很有可能是最后一个，如果是begin()相当于根本没找到或者是空的
            return (i - 1)->second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end

