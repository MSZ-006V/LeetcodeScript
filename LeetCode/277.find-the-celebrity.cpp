/*
 * @lc app=leetcode id=277 lang=cpp
 *
 * [277] Find the Celebrity
 */

// @lc code=start
/* The knows API is defined for you.
      bool knows(int a, int b); */

bool knows(int a, int b);
class Solution {
public:
    int findCelebrity(int n) {
        // time complexity is O(n^3)
        // for(int i = 0, j = 0; i < n; ++i){
        //     for(j = 0; j < n; ++j){
        //         if(i != j && knows(i, j) || !knows(j, i)) break;
        //     }

        //     if(j == n) return i;
        // }

        // return -1;

        // 这种方法时间复杂度只有O(n^2)
        int candidate = 0;
        for(int i = 0; i < n; ++i){
            if(knows(candidate, i)) candidate = i;
        }

        for(int i = 0; i < n; ++i){
            if(candidate != i && knows(candidate, i) || !knows(i, candidate)) return -1;
        }

        return candidate;
    }
};
// @lc code=end

