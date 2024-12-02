/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */

// @lc code=start
class MyHashMap {
private:
    // 采用的是哈希函数，解决哈希冲突的方法是链地址法
    // base = 769是因为这是一个素数，同时不大也不小
    // 链地址法就是把拥有相同哈希key的元素全部放入一个list中，然后再进行查找
    vector<list<pair<int, int>>> data;
    static const int base = 769;
    static int hash(int key) {return key % base;}
public:
    MyHashMap(): data(base) {
        
    }
    
    void put(int key, int value) {
        int h = hash(key);
        for(auto it = data[h].begin(); it != data[h].end(); ++it){
            if((*it).first == key){
                (*it).second = value;
                return;
            }
        }

        data[h].push_back(make_pair(key, value));
    }
    
    int get(int key) {
        int h = hash(key);
        for(auto it = data[h].begin(); it != data[h].end(); ++it){
            if((*it).first == key){
                return (*it).second;
            }
        }

        return -1;
    }
    
    void remove(int key) {
        int h = hash(key);
        for(auto it = data[h].begin(); it != data[h].end(); ++it){
            if((*it).first == key){
                data[h].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

