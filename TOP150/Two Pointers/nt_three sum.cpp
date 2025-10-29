class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // tc O(n^2), sc O(1)

        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for(int k = 0; k < nums.size(); ++k){
            if(nums[k] > 0) return res;
            if(k > 0 && nums[k] == nums[k - 1]) continue;

            int left = k + 1, right = nums.size() - 1;
            while(left < right){
                if(nums[k] + nums[left] + nums[right] > 0){
                    right--;
                }else if(nums[k] + nums[left] + nums[right] < 0){
                    left++;
                }else{
                    res.push_back({nums[k], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left + 1]) left++;
                    while(left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                }
            }
        }

        return res;
    }
};
