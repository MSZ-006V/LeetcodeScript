struct DlinkedNode{
    int key, value;
    DlinkedNode* prev;
    DlinkedNode* next;
    DlinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DlinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DlinkedNode*> cache;
    int size;
    int capacity;
    DlinkedNode* head;
    DlinkedNode* tail;

public:
    LRUCache(int capacity): capacity(capacity), size(0) {
        head = new DlinkedNode();
        tail = new DlinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()){
            return -1;
        }
        DlinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(cache.find(key) == cache.end()){ // 新的节点，新建
            DlinkedNode* node = new DlinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            ++size;
            if(size > capacity){ // 如果新增后大于容量了，就丢弃尾部节点指向的
                DlinkedNode* remove_node = reMoveTail();
                cache.erase(remove_node->key);
                --size;
                delete remove_node;
            }
        }
        else{ // 已存在，更新
            DlinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void moveToHead(DlinkedNode* node){
        reMoveNode(node);
        addToHead(node);
    }

    void addToHead(DlinkedNode* node){
        // 可以画图，很明显的看到需要操作四个指针，所以就有四条指令
        node->next = head->next;
        node->prev = head;
        node->next->prev = node;
        head->next = node;
    }

    DlinkedNode* reMoveTail(){
        DlinkedNode* node = tail->prev;
        reMoveNode(node);
        return node;
    }

    void reMoveNode(DlinkedNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

};