class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(max_reach < i) { // 判断是否能到达当前位置
                return false;
            }
            if(max_reach >= nums.size() - 1){ // 已经可以到达或超过终点，超过直接返回true
                return true;
            }
            max_reach = max(max_reach, i + nums[i]); // 记录最大可达位置
        }

        return false;
    }
};
