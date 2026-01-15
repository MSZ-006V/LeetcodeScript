/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        // 当遇到一个']'的时候, 出栈直到遇到'[', 从出栈的内容中可以提取要重复的字符串
        // 然后再从nums中取出要重复的次数，重复，然后把重复后的字符串全部压入栈，继续执行
        // 先解决内层，然后解决外层，简单题
        string result = "";
        string temp_num = ""; // 暂时存储数字
        stack<char> st; // 储存[, ]还有字母
        stack<int> nums; // 储存重复次数
        for(char c : s){
            if(c == ']'){
                string temp_s = ""; // 存储要重复的字符串
                
                char temp_c = st.top();
                st.pop();

                while(temp_c != '['){
                    temp_s = temp_c + temp_s;
                    temp_c = st.top();
                    st.pop();
                }

                int val = nums.top(); // 从nums中取出要重复的次数
                nums.pop();

                for(int i = 0; i < val; ++i){
                    for(char k:temp_s){
                        st.push(k);
                    }
                }
            }
            else{
                if(c >= '0' && c <= '9'){
                    temp_num = temp_num + c;
                }
                else if(c == '['){
                    int num = stoi(temp_num);
                    nums.push(num);
                    temp_num = "";
                    st.push(c);
                }
                else{
                    st.push(c);
                }
            }
        }

        char output;
        while(!st.empty()){
            output = st.top();
            st.pop();
            result = output + result;
            //cout << output << ' ';
        }
        return result;
    }
};
// @lc code=end

