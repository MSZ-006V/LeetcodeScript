class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // O(n)
        stack<int> st;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            }
            else if (s[i] == ')') {
                if (!st.empty()) {
                    int pos = st.top(); st.pop();
                }
                else {
                    s[i] = '#';
                }
            }
        }
        
        while (!st.empty()) {
            int pos = st.top(); st.pop();
            s[pos] = '#';
        }
        
        string res = "";
        for (auto c : s) {
            if (c != '#') res += c;
        }

        return res;
    }
};