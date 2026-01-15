class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xorr = n;
        for(int i = 0; i < n; ++i){
            xorr ^= i ^ nums[i];
            cout << xorr << endl;
        }
        return xorr;
    }
};
