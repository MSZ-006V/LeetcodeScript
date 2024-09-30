/*
 * @lc app=leetcode.cn id=2115 lang=cpp
 *
 * [2115] 从给定原材料中找到所有可以做出的菜
 */

// @lc code=start
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_map<string, vector<string>> depend;
        unordered_map<string, int> input_rank;

        for(int i = 0; i < n; ++i){
            for(auto& ingredient : ingredients[i]){
                depend[ingredient].push_back(recipes[i]);
            }
            input_rank[recipes[i]] = ingredients[i].size();
        }

        // for(auto pair : depend){
        //     vector<string> temp = depend[pair.first];
        //     cout << pair.first << ": ";
        //     for(auto elem : temp){
        //         cout << elem << ' ';
        //     }
        //     cout << endl;
        // }
        // cout << input_rank["bread"] << endl;
        
        queue<string> que;
        vector<string> result;
        for(int i = 0; i < supplies.size(); ++i){
            que.push(supplies[i]);
        }

        while(que.size() != 0){
            string supply = que.front(); que.pop();
            vector<string> temp = depend[supply];
            if(temp.size() != 0){
                for(int i = 0; i < temp.size(); ++i){
                    input_rank[temp[i]]--;
                    
                    if(input_rank[temp[i]] == 0){
                        que.push(temp[i]);
                        result.push_back(temp[i]);
                    }
                }
            }
        }

        return result;
    }
};
// @lc code=end

