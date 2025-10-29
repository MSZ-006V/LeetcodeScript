class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            // tc O(n), sc O(n)
            int n = coins.size();
            vector<int> dp(amount + 1, amount + 1);
            dp[0] = 0;
    
            for(auto coin : coins){
                for(int i = coin; i <= amount; ++i){
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
                for(auto num : dp){
                    cout << num << ' ';
                }
                cout << endl;
            }
    
    
            return dp[amount] == amount + 1? -1 : dp[amount];
        }
    };
    