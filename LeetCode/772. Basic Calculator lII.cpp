// 和224 227相同，模板相同
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
                if ((c == '+' || c == '-') && 
                    (i == 0 || s[i-1] == '(' || s[i-1] == '+' || s[i-1] == '-' || s[i-1] == '*' || s[i-1] == '/')) {
                    // unary: treat as 0 <op> number. Push 0 to nums so apply will work.
                    // But better: parse the sign with the following number (if it's a number or '(').
                    // We'll push 0 and then push the operator, standardizes handling.
                    nums.push(0);
                }
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