/*
 * @lc app=leetcode id=622 lang=cpp
 *
 * [622] Design Circular Queue
 */

// @lc code=start
class MyCircularQueue {
private:
    vector<int> c_queue;
    int head;
    int tail;
    int capacity;
public:
    MyCircularQueue(int k) {
        head = 0;
        tail = 0;
        capacity = k + 1;
        c_queue = vector<int>(k + 1, 0);
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        c_queue[tail] = value;
        tail = (tail + 1) % capacity;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        head = (head + 1) % capacity;
        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return c_queue[head];
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return c_queue[(tail - 1 + capacity) % capacity];
    }
    
    bool isEmpty() {
        return head == tail;
    }
    
    bool isFull() {
        return ((tail + 1) % capacity) == head;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end

