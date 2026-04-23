struct Entry {
    int key, value, freq; // freq: 该记录被访问的频率
};

class LFUCache {
private:
    int capacity;  // 缓存最大容量
    int min_freq;  // 记录当前整个缓存中，最小的访问频率是多少，用于踢出数据
    
    // key_to_iter: 快速定位。通过 key 找到它在 list 中的位置（迭代器），实现 O(1) 操作
    unordered_map<int, list<Entry>::iterator> key_to_iter;
    
    // freq_to_list: 频率分级。把频率相同的 Entry 放在同一个双向链表里
    // 链表头是最近访问的 (Recently Used)，链表尾是最久未访问的 (Least Recently Used)
    unordered_map<int, list<Entry>> freq_to_list;

    // 核心内部函数：当一个 key 被访问时，它的频率增加，需要“搬家”
    void move(list<Entry>::iterator it) {
        Entry e = *it; // 拷贝当前数据
        
        // 1. 从旧的频率列表里删除
        freq_to_list[e.freq].erase(it); 
        
        // 2. 如果刚才删除的是最小频率的那一摞书，且删完后那一摞空了
        // 则最小频率必须增加（因为已经没有频率为 min_freq 的书了）
        if (freq_to_list[min_freq].empty()) {
            min_freq++;
        }
        
        // 3. 增加频率，并放入新频率列表的最前面（代表它是该频率下最近刚被看过的）
        e.freq++; 
        freq_to_list[e.freq].emplace_front(e); 
        
        // 4. 更新哈希表里的迭代器，指向新频率列表的开头
        key_to_iter[e.key] = freq_to_list[e.freq].begin(); 
    }

public:
    LFUCache(int capacity) : capacity(capacity), min_freq(0) {}

    int get(int key) {
        if (capacity == 0) return -1;
        auto it = key_to_iter.find(key);
        if (it == key_to_iter.end()) return -1; // 没找到直接返回

        int value = it->second->value;
        move(it->second); // 访问成功，频率增加，执行搬家逻辑
        return value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        auto it = key_to_iter.find(key);
        if (it != key_to_iter.end()) { 
            // 情况 A: key 已存在，更新值并增加频率
            it->second->value = value;
            move(it->second);
            return;
        }

        // 情况 B: key 不存在，需要插入新数据
        if (key_to_iter.size() == capacity) { 
            // B-1: 缓存满了，需要踢人
            // 踢掉：频率最小 (min_freq) 且 最久没用 (back()) 的那一个
            auto& lst = freq_to_list[min_freq];
            key_to_iter.erase(lst.back().key); // 从索引中删除
            lst.pop_back();                    // 从列表中删除
        }

        // B-2: 插入新书
        // 刚插入的书频率一定是 1，所以 min_freq 必须重置为 1
        min_freq = 1;
        freq_to_list[1].emplace_front(key, value, 1); 
        key_to_iter[key] = freq_to_list[1].begin();
    }
};