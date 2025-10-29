class Solution {
public:
    string minWindow(string s, string t) {
        // leetcode 76非常经典的题
        // tc O(m + n), sc O(1)
        int ans_l = -1, ans_r = s.size();
        int ht[128]{};
        int num_types = 0;
        for(auto& c : t){
            if(ht[c] == 0) num_types++;
            ht[c]++;
        }
        
        for(int right = 0, left = 0; right < s.size(); ++right){
            ht[s[right]]--;
            if(ht[s[right]] == 0) num_types--;

            while(num_types == 0){
                if(right - left < ans_r - ans_l){
                    ans_l = left;
                    ans_r = right;
                }

                ht[s[left]]++;
                if(ht[s[left]] > 0) num_types++;
                left++;
            }
        }

        return ans_l == -1? "" : s.substr(ans_l, ans_r - ans_l + 1);
    }
};
