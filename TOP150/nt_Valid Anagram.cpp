class Solution {
public:
    bool isAnagram(string s, string t) {
        // tc O(n), sc O(1)
        string hash_s = "00000000000000000000000000";
        string hash_t = "00000000000000000000000000";

        for(auto c : s){
            hash_s[c - 'a']++;
        }
        for(auto c : t){
            hash_t[c - 'a']++;
        }

        return hash_s == hash_t? true : false;
    }
};
