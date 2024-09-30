/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start


class MinStack {
private:
    // st这个栈用作正常使用，min_St用来保存最小值
    stack<int> st;
    stack<int> min_st;
public:
    MinStack() {
        min_st.push(INT_MAX);
    }
    
    void push(int val) {
        // 当每次有元素要push的时候，st正常push，min_st则push当前最小的值，即min(min_st.top(), val)
        st.push(val);
        min_st.push(min(min_st.top(), val));
    }
    
    void pop() {
        st.pop();
        min_st.pop();
        // 出栈一起出就是了，st和min_st中的元素数量是相同的
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

