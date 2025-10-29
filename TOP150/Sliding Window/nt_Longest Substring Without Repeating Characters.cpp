class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // tc O(n), sc O(n)
        unordered_set<char> ht;
        int left = 0;
        int maxLen = 0;
        for(int right = 0; right < s.size(); ++right){
            char ch = s[right];
            while(ht.find(ch) != ht.end()){
                ht.erase(s[left]);
                left++;
            }
            ht.insert(ch);
            if(right - left + 1 > maxLen){
                // cout << right << ' ' << left << endl;
                maxLen = right - left + 1;
            }
        }

        return maxLen;
    }
};
