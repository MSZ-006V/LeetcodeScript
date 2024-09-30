/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */

// @lc code=start
class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;
        int length = moves.size();
        for(int i = 0; i < length; ++i){
            switch(moves[i]){
                case 'R':{
                    x += 1;break;
                };
                case 'L':{
                    x -= 1;break;
                };
                case 'U':{
                    y += 1;break;
                };
                case 'D':{
                    y -= 1;break;
                };
            }
        }
        if(x == 0 && y == 0){
            return true;
        }
        return false;
    }
};
// @lc code=end

