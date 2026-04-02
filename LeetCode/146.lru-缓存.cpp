/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
// 使用一个双向链表和一个unordered_map实现LRU缓存的方法
// 因为需要把最近使用的节点移到最前面，所以需要一个双向链表
struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache; // 模拟哈希表，通过int值直接查询到节点的位置
    int size_;
    int capacity_;
    DLinkedNode* head; // 双向链表的头结点和尾节点
    DLinkedNode* tail; // 这个链表就代表了最近最少使用和最多使用
    // 链表，从头到尾，分别表示每个节点最近使用的顺序，链表头部的节点是最近使用的
    // 链表尾部的节点表示最近最少使用的，所以移到了最后面
public:
    LRUCache(int _capacity): capacity_(_capacity), size_(0) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.count(key) == 0) {
            return -1;
        }
        // 说明key存在，先通过哈希表(unordered_map)进行定位，找到对应的DlinkNode，然后把这个
        // 节点移到双向链表的头部，表示最近使用过，尾部则代表最近最少使用的节点
        DLinkedNode* node = cache[key];
        MoveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (cache.count(key) == 0) {
            // 如果 key 不存在，创建一个新的节点
            DLinkedNode* node = new DLinkedNode(key, value);
            // 添加进哈希表
            cache[key] = node;
            // 添加至双向链表的头部，代表这个节点是最近使用的，所以要移到链表的头部
            AddToHead(node);
            ++size;
            if (size > capacity) {
                // 如果超出容量，删除双向链表的尾部节点，即LRU规则，移除最近最少使用的节点
                DLinkedNode* removed = RemoveTail();
                // 删除哈希表中对应的项
                cache.erase(removed->key);
                // 防止内存泄漏
                delete removed;
                --size;
            }
        }
        else {
            // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
            DLinkedNode* node = cache[key];
            node->value = value;
            MoveToHead(node);
        }
    }

    void AddToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void RemoveNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void MoveToHead(DLinkedNode* node) {
        RemoveNode(node); // 先把原来的地方删除
        AddToHead(node); // 然后再把新的插入头节点head的后面
    }

    DLinkedNode* RemoveTail() { // 即删除tail尾节点的上一个节点
        DLinkedNode* node = tail->prev;
        RemoveNode(node);
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

