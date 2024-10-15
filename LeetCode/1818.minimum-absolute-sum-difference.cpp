/*
 * @lc app=leetcode id=1818 lang=cpp
 *
 * [1818] Minimum Absolute Sum Difference
 */

// @lc code=start
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        // 比较经典，想要绝对值最小，就找到和nums2[i]中对应数最接近的两个数就可以
        // 所以另外拿出一个search(nums1排序版)，用来搜索
        // 需要特殊处理的点就是r1返回的开头或者结尾的时候，其余情况就是比较r1和r1-1的哪个绝对值比较小就可以了
        int length = nums1.size();
        long long abs_v = 0;

        for(int i = 0; i < length; ++i){
            abs_v += abs(nums1[i] - nums2[i]);
        }

        long long abs_v_min = abs_v;

        vector<int> search(nums1.begin(), nums1.end());
        sort(search.begin(), search.end());

        for(int i = 0; i < length; ++i){
            // search target is nums2[i], array is in search
            // raw v is abs(nums1[i] - nums2[i])
            int r1 = ranges::lower_bound(search.begin(), search.end(), nums2[i]) - search.begin();
            int min_v = 0;
            if(r1 == 0){
                min_v = abs(search[r1] - nums2[i]);
            }
            else if(r1 == length){
                min_v = abs(search[r1 - 1] - nums2[i]);
            }
            else{
                min_v = min(abs(search[r1] - nums2[i]), abs(search[r1 - 1] - nums2[i]));
                // cout << search[r1] << ' ' << search[r1 - 1] << endl;
                // cout << search[r1] - nums2[i] << ' ' << abs(nums1[r1 - 1] - nums2[i]) << endl;
            }
            abs_v_min = min(abs_v_min, abs_v - abs(nums1[i] - nums2[i]) + min_v);
            // cout << "min_v is " << abs_v_min << endl;
        }

        return (abs_v_min % 1000000007);
    }
};
// @lc code=end

