class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        for(auto& n : nums1){
            nums.push_back(n);
        }
        for(auto& n : nums2){
            nums.push_back(n);
        }
        sort(nums.begin(), nums.end());

        if(nums.size() % 2 == 1){
            return double(nums[nums.size() / 2]);
        }
        else{
            return double(nums[nums.size() / 2] + nums[nums.size() / 2 - 1]) / 2;
        }
    }
};
