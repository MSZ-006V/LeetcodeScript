class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // tc O(n), sc O(n)
        // 使用逆波兰表达式，解析时从左到右扫描表达式，遇到操作数就入栈，
        // 遇到操作符就弹出两个操作数进行计算，结果再入栈
        stack<string> st;

        for(string& c : tokens){
            if(c == "+" || c == "-" || c == "*" || c == "/"){
                string num1 = st.top(); st.pop();
                string num2 = st.top(); st.pop();
                if(c == "+"){
                    int res = std::stoi(num1) + std::stoi(num2);
                    st.push(std::to_string(res));
                }
                else if(c == "-"){
                    int res = std::stoi(num2) - std::stoi(num1);
                    st.push(std::to_string(res));
                }
                else if(c == "*"){
                    int res = std::stoi(num1) * std::stoi(num2);
                    st.push(std::to_string(res));
                }
                else if(c == "/"){
                    int res = std::stoi(num2) / std::stoi(num1);
                    st.push(std::to_string(res));
                }
            }
            else{
                st.push(c);
            }
        }
        return std::stoi(st.top());
    }
};
