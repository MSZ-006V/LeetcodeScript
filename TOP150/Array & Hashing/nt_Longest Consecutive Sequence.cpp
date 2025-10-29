class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // tc O(n), sc O(n)
        unordered_set<int> numset(nums.begin(), nums.end());
        int longest = 0;

        for(auto& num : numset){
            // 当前元素的上一个元素找不到，说明这个元素可以作为一个连续递增子序列的开头
            if(numset.find(num - 1) == numset.end()){
                int length = 1;
                // 以当前元素num作为开头，一直向后找
                while(numset.find(num + length) != numset.end()){
                    length++;
                }
                longest = max(longest, length);
            }
        }

        return longest;
    }
};
