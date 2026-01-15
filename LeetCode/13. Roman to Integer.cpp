class Solution {
public:
    int tran(char a){
        switch(a){
            case 'I' :return 1; break;
            case 'V': return 5; break;
            case 'X': return 10; break;
            case 'L': return 50; break;
            case 'C': return 100; break;
            case 'D': return 500; break;
            case 'M': return 1000; break;
            default: return 0; break;
        }
    }
    int romanToInt(string s) {
        int res = 0;
        for(int i = 0; i < s.size() - 1; ++i){
            if(tran(s[i]) < tran(s[i + 1])){
                res -= tran(s[i]);
            }
            else{
                res += tran(s[i]);
            }
        }

        return res + tran(s[s.size() - 1]);
    }
};