/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
struct MListNode{
    int val;
    MListNode* next;
    MListNode():val(0), next(nullptr){}
    MListNode(int _val):val(_val), next(nullptr){}
    MListNode(int _val, MListNode* _next):val(_val), next(_next){}
};
class MyLinkedList {
private:
    int size;
    MListNode* dh;
public:
    MyLinkedList() {
        dh = new MListNode();
        size = 0;
    }
    
    int get(int index) {
        if(index >= size) return -1;
        MListNode* cur = dh;
        while(index >= 0){
            cur = cur->next;
            index--;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        MListNode* node = new MListNode(val);
        MListNode* temp = dh->next;
        dh->next = node;
        node->next = temp;
        size++;
    }
    
    void addAtTail(int val) {
        MListNode* cur = dh;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        MListNode* node = new MListNode(val);
        cur->next = node;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size) return;
        MListNode* cur = dh;
        while(index > 0){
            cur = cur->next;
            index--;
        }
        MListNode* node = new MListNode(val, cur->next);
        cur->next = node;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size) return;
        MListNode* cur = dh;
        while(index > 0){
            cur = cur->next;
            index--;
        }
        MListNode* temp = cur->next;
        cur->next = cur->next->next;
        size--;
        delete(temp);
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

