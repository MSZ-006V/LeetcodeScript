class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // tc O(n), sc O(n)
        unordered_set<int> numset;
        for(auto num : nums){
            if(numset.find(num) != numset.end()){
                return true;
            }
            numset.insert(num);
        }

        return false;
    }
};