/*
 * @lc app=leetcode id=641 lang=cpp
 *
 * [641] Design Circular Deque
 */

// @lc code=start
class MyCircularDeque {
private:
    vector<int> cdque;
    int head;
    int tail;
    int capacity;
public:
    MyCircularDeque(int k) {
        head = 0;
        tail = 0;
        capacity = k + 1;
        cdque = vector<int>(capacity, 0);
    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }
        head = (head - 1 + capacity) % capacity; // 从头插入的话，head应该时减小而不是增大
        cdque[head] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        cdque[tail] = value;
        tail = (tail + 1) % capacity; // 从尾部插入，tail应该增大
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        head = (head + 1) % capacity;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        tail = (tail - 1 + capacity) % capacity;
        return true;
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        return cdque[head];
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        return cdque[(tail - 1 + capacity) % capacity];
    }
    
    bool isEmpty() {
        return head == tail;
    }
    
    bool isFull() {
        return ((tail + 1) % capacity) == head;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end

