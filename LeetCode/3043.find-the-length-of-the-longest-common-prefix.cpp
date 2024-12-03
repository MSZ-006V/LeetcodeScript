/*
 * @lc app=leetcode id=3043 lang=cpp
 *
 * [3043] Find the Length of the Longest Common Prefix
 */

// @lc code=start
class trie{
private:
    vector<trie*> next;
    bool isEnd;
public:
    trie(): next(26), isEnd(false){}

    void insert(string s){
        trie* root = this;
        for(char c : s){
            if(root->next[c - '0'] == nullptr){
                root->next[c - '0'] = new trie();
            }
            root = root->next[c - '0'];
        }
        root->isEnd = true;
    }

    int searchPrefix(string s){
        trie* root = this;
        int index = 0;
        for(char c : s){
            root = root->next[c - '0'];
            if(root == nullptr) return index;
            index++;
        }
        return index;
    }
};
class Solution {
public:
    // time complexity is O(N^2), or O(Nk), k maybe the length of string
    // 慢一点的原因是因为多了个把数字转换为字符串的步骤，否则也挺快的
    // 这两种方法都差不多
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        trie* node = new trie();
        for(auto n : arr1){
            node->insert(std::to_string(n));
        }

        int long_prefix = 0;
        for(auto n : arr2){
            string cur = std::to_string(n);
            int index = node->searchPrefix(cur);

            if(index + 1 > long_prefix){
                long_prefix = index;
            }
        }

        return long_prefix;

        // 更快更简单的用哈希表的方法，把arr1中所有数字的前缀放入表中
        // 遍历arr2，不断找出前缀，然后记录
        // 这个方法比trie稍微快一点
        // time complexity is O((n + m)logU), n is length of arr1, m is length of arr2, U is the maximum value in array
        // unordered_set<int> st;
        // for (int x : arr1) {
        //     for (; x; x /= 10) {
        //         st.insert(x);
        //     }
        // }

        // int mx = 0;
        // for (int x : arr2) {
        //     for (; x && !st.contains(x); x /= 10);
        //     mx = max(mx, x);
        // }
        // return mx ? to_string(mx).length() : 0;
    }
};
// @lc code=end

