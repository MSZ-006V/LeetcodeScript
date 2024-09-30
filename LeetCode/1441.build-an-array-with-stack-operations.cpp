/*
 * @lc app=leetcode id=1441 lang=cpp
 *
 * [1441] Build an Array With Stack Operations
 */

// @lc code=start
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int index = 0;
        int index_range = 1;
        vector<string> result;
        while(index < target.size()){
            if(target[index] == index_range){
                result.push_back("Push");
                index++;
            }
            else{
                result.push_back("Push");
                result.push_back("Pop");
            }
            index_range++;
        }
        
        return result;
    }
};
// @lc code=end

