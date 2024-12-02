/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 */

// @lc code=start
class MyHashSet {
    // 和706十分类似，一个是存储键值对pair，一个是只存储key，解决哈希冲突的
    // 方法都是链地址法
private:
    vector<list<int>> data;
    static const int base = 769;
    static const int hash(int key) {return key % 769;}
public:
    MyHashSet(): data(769) {
        
    }
    
    void add(int key) {
        int h = hash(key);
        for(auto it = data[h].begin(); it != data[h].end(); ++it){
            if((*it) == key){
                return;
            }
        }
        data[h].push_back(key);
    }
    
    void remove(int key) {
        int h = hash(key);
        for(auto it = data[h].begin(); it != data[h].end(); ++it){
            if((*it) == key){
                data[h].erase(it);
                return;
            }
        }
        return;
    }
    
    bool contains(int key) {
        int h = hash(key);
        for(auto it = data[h].begin(); it != data[h].end(); ++it){
            if((*it) == key){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

