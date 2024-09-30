/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
private:
    stack<int> instack;
    stack<int> outstack;
public:
    MyQueue() {

    }

    void in2out(){
        while(instack.size() != 0){
            outstack.push(instack.top());
            instack.pop();
        }
    }
    
    void push(int x) {
        instack.push(x);
    }
    
    int pop() {
        if(outstack.size() == 0){
            in2out();
        }
        int x = outstack.top();
        outstack.pop();
        return x;
    }
    
    int peek() {
        if(outstack.size() == 0){
            in2out();
        }
        return outstack.top();
    }
    
    bool empty() {
        if(instack.size() == 0 && outstack.size() == 0){
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

