/*
 * @lc app=leetcode id=856 lang=cpp
 *
 * [856] Score of Parentheses
 */

// @lc code=start
class Solution {
public:
    int scoreOfParentheses(string s) {
        // 初始化将答案 0 放入栈中，从前往后处理整个s
        // 当遇到 ( 则存入一个占位数值0，遇到 ) 取出栈顶元素 cur
        // 根据栈顶元素数值分情况讨论：
        // 栈顶元素 cur=0，即当前的 ) 的前一元素就是 ( ，根据 () 得一分的规则可知，我们本次操作得到的分值为 1
        // 栈顶元素 cur=0，即当前 ) 与其匹配的 ( 中间相隔了其他字符，根据 (A) 的得分规则，此时可知得分为 cur×2
        int val = 0;
        stack<int> st;
        st.push(0);
        for(auto c : s){
            if(c == '('){
                st.push(0);
            }
            else{ // c == ')'
                int cur = st.top(); st.pop();
                int ncur = st.top(); st.pop();
                st.push(ncur + max(2 * cur, 1));
            }
        }

        return st.top();
    }
};
// @lc code=end

