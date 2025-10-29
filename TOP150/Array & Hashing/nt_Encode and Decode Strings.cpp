class Solution {
public:
    // 对于strs是["neet","code","love","you"]
    // 加密为4#neet4$code4#love3#you
    // 然后再进行解码，比较简单，但是题目没有提供如何进行加密，这道题是一道开放题
    string encode(vector<string>& strs) {
        // tc O(n), sc O(1)
        string s = accumulate(strs.begin(), strs.end(), string(), [](string a, string b){
            int s_a = a.size();
            int s_b = b.size();
            return move(a) + to_string(b.size()) + "#" + b;
        });
        cout << s;
        return s;
    }

    vector<string> decode(string s) {
        // tc O(n), sc O(1)
        vector<string> res;
        int index = 0;
        while(index < s.size()){
            int j = index;
            while(s[j] != '#') j++;

            int length = stoi(s.substr(index, j - index));
            index = j + 1;
            j = index + length;
            res.push_back(s.substr(index, length));
            index = j;
        }
        return res;
    }
};
