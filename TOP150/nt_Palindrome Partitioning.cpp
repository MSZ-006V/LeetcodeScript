class Solution {
public: 
    // tc O(n * 2^n), sc O(n)
    vector<vector<string>> res;
    bool isPalindrome(string s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void backtracking(string s, int index, vector<string> tmp){
        if(index == s.size()){
            res.push_back(tmp);
            return;
        }

        for(int i = index; i < s.size(); ++i){
            if(isPalindrome(s, index, i)){
                tmp.push_back(s.substr(index, i - index + 1));
                backtracking(s, i + 1, tmp);
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int index = 0;
        vector<string> tmp;

        backtracking(s, index, tmp);
        return res;
    }
};
