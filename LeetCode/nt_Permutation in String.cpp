class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len = s1.size();
        string s1_ht = "00000000000000000000000000";
        string s2_ht = "00000000000000000000000000";
        for(auto& c : s1){
            s1_ht[c - 'a']++;
        }
        int left = 0;
        bool result = false;
        for(int right = 0; right < s2.size(); ++right){
            s2_ht[s2[right] - 'a']++;
            while(right - left + 1 > len){
                s2_ht[s2[left] - 'a']--;
                left++;
            }

            if(s1_ht == s2_ht) result = true;
        }

        return result;
    }
};
