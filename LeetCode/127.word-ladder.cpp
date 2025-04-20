/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordset(wordList.begin(), wordList.end()); // 将vector转换为set，方便进行查找
        if(wordset.count(endWord) == 0) return 0;
        unordered_map<string, int> visited; // 记录节点是否被访问过，同时记录路径长度
        queue<string> que;

        que.push(beginWord);
        visited.insert({beginWord, 1});
        
        // 使用BFS进行搜索，因为当BFS解决最短路径的时候，只要能够搜索到终点，那就一定是最短路径
        // 这是由于BFS本身搜索的特点所保证的，与DFS不同
        // 如果要使用DFS进行搜索，还需要比对不同路径之间不同的长度，找出里面的最短路径
        while(!que.empty()){
            string cur = que.front();que.pop();
            int path_length = visited[cur];
            if(cur == endWord) return path_length;

            for(int i = 0; i < cur.size(); ++i){
                string new_word = cur;
                for(int j = 0; j < 26; ++j){
                    new_word[i] = 'a' + j;
                    // if(new_word == endWord) return path_length + 1; // 找到了最后一个单词，返回路径长度
                    if(wordset.count(new_word) != 0 && // wordset里面有，同时没有被访问过
                    visited.find(new_word) == visited.end()){
                        que.push(new_word);
                        visited.insert({new_word, path_length + 1});
                    }
                }
            }
        }
        return 0;
    }
};
// @lc code=end

