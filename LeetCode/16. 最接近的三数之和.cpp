class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // tc O(n^2), sc O(logn)
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int gap = INT_MAX;
        int res = 0;

        for(int i = 0; i < n - 1; ++i){
            if(i > 1 && nums[i] == nums[i - 1]) continue;

            int left = i + 1, right = n - 1;
            while(left < right){
                int v = nums[left] + nums[right] + nums[i];
                if(abs(v - target) < gap){
                    cout << nums[i] << ' ' << nums[left] << ' ' << nums[right] << endl;
                    gap = abs(v - target);
                    res = v;
                }
                if(v < target) left++;
                else right--;
            }
        }

        return res;
    }
};