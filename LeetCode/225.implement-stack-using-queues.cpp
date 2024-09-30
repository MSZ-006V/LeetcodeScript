/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
class MyStack {
private:
    queue<int> que_main;
    queue<int> que_assi;
public:
    MyStack() {
        
    }


    void push(int x) {
        // 入栈时，压入que-assi, 然后把main队列全部元素再压入assi，这样子
        // assi队列头就正好是栈顶元素，然后再把assi的元素全部再压入main就好
        que_assi.push(x);
        while(que_main.size() != 0){
            que_assi.push(que_main.front());
            que_main.pop();
        }
        while(que_assi.size() != 0){
            que_main.push(que_assi.front());
            que_assi.pop();
        }
    }
    
    int pop() {
        int ret = que_main.front();
        que_main.pop();
        return ret;
    }
    
    int top() {
        return que_main.front();
    }
    
    bool empty() {
        if(que_main.size() == 0){
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

