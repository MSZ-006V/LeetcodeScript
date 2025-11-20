// 这道题是标准模板，适用于224 计算器 I 和 772 计算器 III
class Solution {
public:
    int precedence(char op){
        if(op == '+' || op == '-') return 1;
        if(op == '*' || op == '/') return 2;
        return 0; // (, )
    }
    void apply(stack<int>& nums, stack<char>& ops){
        if(nums.size() < 2 || ops.empty()) return;

        int b = nums.top(); nums.pop();
        int a = nums.top(); nums.pop();
        char op = ops.top(); ops.pop();
        int res = 0;
        if(op == '+') res = a + b;
        else if(op == '-') res = a - b;
        else if(op == '*') res = a * b;
        else if(op == '/') res = a / b;

        nums.push(res);
    }
    int calculate(string s) {
        int n = s.size();
        stack<int> nums;
        stack<char> ops;

        for(int i = 0; i < s.size();){
            char c = s[i];
            if(c == ' ') {++i; continue;}

            if(c == '('){
                ops.push(c);
                ++i;
            }
            else if(c == ')'){
                while(!ops.empty() && ops.top() != '(') apply(nums, ops);

                if(!ops.empty() && ops.top() == '(') ops.pop(); // 计算完后把剩下的 ( 给弹出
                ++i;
            }
            else if(isdigit(c)){
                int num = 0;
                while(i < n && isdigit(s[i])){
                    num= num * 10 + (s[i] - '0');
                    ++i;
                }
                nums.push(num);
            }
            else{
                // 处理一元运算符，如5 + (-3), (-3) * 6, 处理这种符号
                // 如果满足下面两种条件，则认为是一个一元运算符：
                // 1. 当前字符是 '+' 或 '-'
                // 2. 前一个字符是表达式开头，或者是 '(' ，或者是 +、-、*、/ 
                // push 0 作为占位符, 让一元运算符变成二元运算符, 即把 -3 变成 0 - 3
                if ((c == '+' || c == '-') && 
                    (i == 0 || s[i-1] == '(' || s[i-1] == '+' || s[i-1] == '-' || s[i-1] == '*' || s[i-1] == '/')) {
                    nums.push(0);
                }
                // 这里判断符号是 >= , 因为如果是 +, -, 他们优先级相同
                // 如果是 * /, 他们优先级相同
                // 只有当当前符号优先级小于等于栈顶符号时，才需要计算
                while(!ops.empty() && precedence(ops.top()) >= precedence(c)){
                    apply(nums, ops);
                }
                ops.push(c);
                ++i;
            }
        }
        
        while(!ops.empty()) apply(nums, ops);

        return (int)nums.top();
    }
};