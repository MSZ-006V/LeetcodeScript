class MinStack {
    // tc O(1), sc O(n)
    // 使用一个栈来实现最小栈，每个方法都是O(1)的，可以实现查找最小元素最快
    // 用的一个比较巧妙地方法，应该是把差值放入栈中，而不是直接压入真实元素
private:
    int min;
    stack<long> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(0);
            min = val;
        }
        else{
            st.push(val - min);
            if(val < min) min = val;
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long pope = st.top();
        st.pop();       

        if(pope < 0) min = min - pope; 
    }
    
    int top() {
        long tope = st.top();
        return (tope > 0)?(tope + min) : (int)min;
    }
    
    int getMin() {
        return (int)min;
    }
};
