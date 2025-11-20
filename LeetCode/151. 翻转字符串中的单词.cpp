class Solution {
public:
    void reverseString(string& s, int l, int r){
        while(l < r) swap(s[l++], s[r--]);
    }
    string reverseWords(string s) {
        // 原地，指针写法
        // tc O(n), sc O(1)
        int n = s.size();
        int j = 0;
        
        for(int i = 0; i < n; ++i){
            if(s[i] != ' '){
                if(j != 0) s[j++] = ' ';
                
                int k = i;
                while(k < n && s[k] != ' '){
                    s[j++] = s[k++];
                }
                i = k;
            }
        }
        s.resize(j);
        reverse(s.begin(), s.end());
        cout << s << endl;

        int start = 0;
        for(int i = 0; i <= j; ++i){
            if(i == j || s[i] == ' '){
                reverseString(s, start, i - 1);
                start = i + 1;
            }
        }

        return s;
    }
};