class Solution {
public:
    // tc O(n), sc O(n)
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;

        for(int i = n - 1; i >= 0; --i){
            if(s[i] == '0'){
                dp[i] = 0;
            }
            else{
                // 此时代表dp[i]作为单个字符进行解码，不跟后面数字组合
                dp[i] = dp[i + 1]; 

                // 代表跟后面数字组合进行解码，要求就应该是s[i]在1~2, s[i+1]在0~6
                if(i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7')){
                    dp[i] += dp[i + 2]; // 加上s[i+2:]的数量，就代表把s[i]s[i+1]解码一个数，后面的数量就是s[i+2:]的数量
                }
            }
        }
        for(auto num : dp){
            cout << num << ' ';
        }
        return dp[0];
    }
};
    