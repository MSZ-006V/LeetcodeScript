class Solution {
public:
    bool isValid(string s) {
        // tc O(n), sc O(n)
        stack<char> st;
        char tempe;

        for(auto& c : s){
            if(c == ']'){
                if(!st.empty()){
                    tempe = st.top(); st.pop();
                    if(tempe != '[') return false;
                }
                else{
                    return false;
                }
            }
            else if(c == ')'){
                if(!st.empty()){
                    tempe = st.top(); st.pop();
                    if(tempe != '(') return false;
                }
                else{
                    return false;
                }
            }
            else if(c == '}'){
                if(!st.empty()){
                    tempe = st.top(); st.pop();
                    if(tempe != '{') return false;          
                }
                else{
                    return false;
                }
            }
            else{
                st.push(c);
            }
        }

        return st.empty()?true:false;
    }
};
