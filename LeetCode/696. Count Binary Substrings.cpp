class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0;
        int prev = 0;
        int cur_g = 1;
        for(int i = 1; i < s.size(); ++i){
            if(s[i] == s[i - 1]){
                cur_g++;
            }
            else{
                res += min(prev, cur_g);
                prev = cur_g;
                cur_g = 1;
            }
        }

        res += min(prev, cur_g);
        return res;
    }
};