class Solution {
public:
    // tc O(n * 4^n), sc O(n)
    vector<vector<char>> numbers = {
        {'a', 'b', 'c'}, 
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}
    };
    vector<string> res;
    void backtracking(int index, string digits, string& tmp){
        if(index == digits.size()){
            res.push_back(tmp);
            return;
        }

        for(auto digit : numbers[digits[index] - '0' - 2]){
            tmp += digit;
            backtracking(index + 1, digits, tmp);
            tmp = tmp.substr(0, tmp.size() - 1);
        }
        
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        string s = "";
        int index = 0;
        backtracking(index, digits, s);

        return res;
    }
};

// iteration 方法，时间复杂度和空间复杂度都是完全一样的
// 思路就是当遍历到某个digit的时候，把目前res数组里面所有的元素拿出来，加上当前这个digit可以代表的所有字符
// 然后再放回去，很简单的思路
class Solution {
public:
    vector<vector<char>> numbers = {
        {'a', 'b', 'c'}, 
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}
    };
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<string> res = {""};

        for(char digit : digits){
            vector<string> tmp;
            for(string &cur_tmp : res){
                for(char c : numbers[digit - '0' - 2]){
                    tmp.push_back(cur_tmp + c);
                }
            }
            res = tmp;
        }

        return res;
    }
};
