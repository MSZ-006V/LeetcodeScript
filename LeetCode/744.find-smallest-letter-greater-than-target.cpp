/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 */

// @lc code=start
class Solution {
public:
    int bs(vector<char>& letters, char target){
        int left = 0, right = letters.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(target > letters[mid]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return left;
    }
    char nextGreatestLetter(vector<char>& letters, char target) {
        // 因为题目要求，如果整个数组中所有的数都没有大于target的
        // 就返回数组第一个元素，所以需要特殊处理
        if(target >= letters[letters.size() - 1]){ 
            return letters[0];
        }
        int res = bs(letters, target + 1); // 转化为找target + 1的，原来的binary search算法不变
        return letters[res];
    }
};
// @lc code=end

