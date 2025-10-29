class Solution {
public:
    // 可以理解为分层的跳法，从i = 0开始，最开始的第一层的最大范围就是0 + nums[0]
    // 最少都需要走一步
    // 所以每次在最开始i = 0都一定会刷新一次cur_pos，刷新后
    // 当下一次i == cur_pos时，说明到达了第二层的边界，再跳一次，所以res++
    // 以此类推

    // 不断取最大值，表示当前层内所有位置的最远可达点
    // 当 i 走到了当前层的最远边界 cur_pos，说明这一层已经遍历完了。
    // 你必须跳一次（res++），才能进入下一层。
    // 更新新的边界 cur_pos = max_reach，表示下一层的范围。
    int jump(vector<int>& nums) {
        int res = 0;
        int cur_pos = 0;
        int max_reach = 0;
        for(int i = 0; i < nums.size() - 1; ++i){
            max_reach = max(max_reach, i + nums[i]);
            if(i == cur_pos){
                cur_pos = max_reach;
                res++;
            }
        }

        return res;
    }
};
