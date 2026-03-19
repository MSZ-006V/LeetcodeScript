class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto c : s){
            if(c == ')' || c == '}' || c == ']'){
                if(st.empty() 
                || (c == ')' && st.top() != '(') 
                || (c == ']' && st.top() != '[') 
                || (c == '}' && st.top() != '{') 
                ){
                    return false;
                }
                st.pop();
            }
            else {
                st.push(c);
            }
        }

        if(st.empty()) return true;
        return false;
    }
};
