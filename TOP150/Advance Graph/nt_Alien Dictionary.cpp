class Solution {
public:
    // leetcode269 外星语言
    // 拓扑排序
    string foreignDictionary(vector<string>& words) {
        unordered_map<int, vector<int>> cs;
        vector<int> input_rank(26, 0);
        vector<bool> seen(26, false);

        for(auto &w : words){ // 统计出现过的字母
            for(char c : w){
                seen[c - 'a'] = true;
            }
        }

        for(int i = 1; i < words.size(); ++i){
            // 比较words[i - 1], words[i]
            string &w1 = words[i - 1];
            string &w2 = words[i];
            int idx = 0;
            int len = min(w1.size(), w2.size());

            while(idx < len && w1[idx] == w2[idx]){
                idx++;
            }

            // 如果idx == len，说明w1是w2的前缀，如果w1比w2长，则invalid
            if(idx == len && w1.size() > w2.size()) return "";
            // 记录边
            if(idx < len){
                int u = w1[idx] - 'a';
                int v = w2[idx] - 'a';
                cs[u].push_back(v);
                input_rank[v]++;
            }
        }

        queue<int> que;
        string res = "";
        for(int i = 0; i < 26; ++i){
            if(input_rank[i] == 0 && seen[i]){ // 出现过的字母，同时入度为0，才能入队
                que.push(i);
            }
        }

        while(!que.empty()){
            auto cur = que.front(); que.pop();
            res += (cur + 'a');

            auto &edge = cs[cur];
            for(auto e : edge){
                input_rank[e]--;
                if(input_rank[e] == 0){
                    que.push(e);
                }
            }
        }

        int letter_num = 0;
        for(auto s : seen) if(s) letter_num++; 
        if(res.size() != letter_num) return ""; // 如果结果中没有包含所有出现的字母，同样是invaild情况

        cout << res << endl;
        return res;
    }
};
