class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // tc O(m*n), sc O(m) 
        unordered_map<string, vector<string>> ht;
        string tempht = "00000000000000000000000000";

        for(auto& str : strs){
            tempht = "00000000000000000000000000";
            for(auto& c : str){
                tempht[c - 'a']++;
            }
            ht[tempht].push_back(str);
        }

        vector<vector<string>> result;
        for(auto& p : ht){
            vector<string>& groups = p.second;
            result.push_back(groups);
        }

        return result;
    }
};
