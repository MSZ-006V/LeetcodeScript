class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        vector<vector<int>> intervals;
        unordered_map<char, vector<int>> ht;
        for(int i = 0; i < s.size(); ++i){
            if(ht.find(s[i]) == ht.end()){
                ht[s[i]] = {i, i};
            }
            else{
                ht[s[i]][1] = i;
            }
        }

        for(auto& [val, se] : ht){
            // cout << val << ' ' << se[0] << ' ' << se[1] << endl;
            intervals.push_back(se);
        }

        sort(intervals.begin(), intervals.end(), [](auto& a, auto & b){
            return a[0] < b[0];
        });

        int left = intervals[0][0], right = intervals[0][1];
        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i][0] > right){
                res.push_back(right - left + 1);
                left = intervals[i][0];
                right = intervals[i][1];
            }
            else{
                right = max(right, intervals[i][1]);
            }
        }
        res.push_back(right - left + 1);

        return res;
    }
};


// 第二种方法
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastIndex;
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i]] = i;
        }

        vector<int> res;
        int size = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            size++;
            // 记录当前分区最大的结束位置
            end = max(end, lastIndex[s[i]]);

            if (i == end) { // 当到达结束位置的时候，就说明前面的子串包含的单词只在这个子串里面出现，并且不会再出现在后面的子串中
                res.push_back(size);
                size = 0;
            }
        }
        return res;
    }
};