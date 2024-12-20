class Solution {
public:
    bool isPalindrome(string s) {
        // tc O(n), sc O(n)
        // 这题其实不算简单的，首先题目要求回文序列只能是字母和数字，所以最开始先遍历一遍，取出字母和数字，同时大写转小写
        // 然后再常规的进行比较，主要是第一步会耗时很久，不是一下子能想到，记住这种方法
        string new_s = "";
        for(auto& c : s){
            if(c >= 65 && c <= 91) new_s += c - 'A' + 'a';
            else if(c >= 97 && c <= 122) new_s += c;
            else if(c >= 48 && c <= 57) new_s += c;
        }
        int left = 0, right = new_s.size() - 1;
        while(left < right){
            if(new_s[left] != new_s[right]) return false;
            left++;
            right--;
        }

        return true;
    }
};
