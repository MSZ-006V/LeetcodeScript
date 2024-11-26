/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res = "";
        int lnum = 0; // 动态计算左括号的数量，因为只要右括号还有个数，右括号就可以放进
        int rnum = count(s.begin(), s.end(), ')'); // 计算右括号的个数
        int num = 0;
        for(char c : s){
            if(c == '('){
                if(rnum > 0){ // 如果右括号还有个数，就一定可以放入左括号，
                    res += c;
                    rnum--; // 减少一个
                    lnum++; // 加一个
                }
            }
            else if(c == ')'){
                if(lnum > 0){ // 右括号要合法一定要有左括号，所以只有左括号有的时候才行
                    res += c;
                    lnum--; // 减一个可以用的左括号
                }
                else{ 
                // 这种情况是对应 '))((' 这种例子的，
                // 这种情况最开始的两个右括号会把rnum消耗完，这样子后面的两个左括号就不合法，不会进入字符串了
                    rnum--;
                }
            }
            else{
                res += c;
            }
        }

        return res;
    }
};
// @lc code=end

