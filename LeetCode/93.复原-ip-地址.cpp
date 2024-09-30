/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
private:
    vector<string> result;
public:
    void backtracking(string& s, int start_index, int point_num){
        if(point_num == 3){
            if(isVaild(s, start_index, s.size() - 1)){
                result.push_back(s);
            }
            return;
        }
        for(int i = start_index; i < s.size(); ++i){
            if(isVaild(s, start_index, i)){
                s.insert(s.begin() + i + 1, '.');
                point_num++;
                backtracking(s, i + 2, point_num);
                point_num--;
                s.erase(s.begin() + i + 1);
            }
            else break;
        }
    }
    bool isVaild(string& s, int start, int end){
        if(start > end) return false;
        if(s[start] == '0' && start != end) return false;
        int num = 0;
        for(int i = start; i <= end; ++i){
            if(s[i] > '9' || s[i] < '0') return false;
            num = num * 10 + (s[i] - '0');
            if(num > 255) return false;
        }
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        backtracking(s, 0, 0);
        return result;
    }
};
// @lc code=end

