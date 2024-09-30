/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        stack<int> sq;
        sq.push(1);
        int sign = 1;

        int ret = 0;
        int i = 0;
        while(i < s.length()){
            if(s[i] == ' '){
                ++i;
            }
            else if(s[i] == '+'){
                sign = sq.top();
                ++i;
            }
            else if(s[i] == '-'){
                sign = -sq.top();
                ++i;
            }
            else if(s[i] == '('){
                sq.push(sign);
                ++i;
            }
            else if(s[i] == ')'){
                sq.pop();
                ++i;
            }
            else{
                long num = 0;
                while(i < s.length() && s[i] >= '0' && s[i] <= '9'){
                    num = num * 10 + s[i] - '0';
                    ++i;
                }
                ret += sign * num;
            }
            
        }
        return ret;
    }
};
// @lc code=end

