class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> ht;
        for(char c : s){
            ht[c]++;
        }
        string res = "";
        bool in_ans[26]{};
        for(char c : s){
            ht[c]--;
            if(in_ans[c - 'a']) continue;
            while(!res.empty() && c < res.back() && ht[res.back()]){
                in_ans[res.back() - 'a'] = false;
                res.pop_back();
            }
            res += c;
            in_ans[c - 'a'] = true;
        }

        return res;
    }
};