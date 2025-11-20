class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int left = 0, right = 0;
        int max_len = 0;

        for(int i = n - 1; i >= 0; --i){
            for(int j = i; j < n; ++j){
                if(s[i] == s[j]){
                    if(j - i <= 1){
                        dp[i][j] = true;
                    }
                    else if(dp[i + 1][j - 1]){
                        dp[i][j] = true;
                    }
                }

                if(dp[i][j] && j - i + 1 > max_len){
                    left = i;
                    right = j;
                    max_len = j - i + 1;
                }
            }
        }

        return s.substr(left, max_len);
    }
};
    