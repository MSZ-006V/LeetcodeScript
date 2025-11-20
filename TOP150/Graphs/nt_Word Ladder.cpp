class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 这是一个典型的BFS方法
        unordered_set<string> words(wordList.begin(), wordList.end());
        if(words.find(endWord) == words.end()) return 0;

        unordered_map<string, int> visited;
        queue<string> que;
        que.push(beginWord);
        visited[beginWord] = 1;

        while(!que.empty()){
            // 方法1，visited数组里面也保存变换次数
            string cur = que.front(); que.pop();
            int path_length = visited[cur];
            
            for(int k = 0; k < cur.size(); ++k){
                string ncur = cur;
                for(int i = 0; i < 26; ++i){
                    ncur[k] = 'a' + i;
                    if(ncur == endWord) return path_length + 1;
                    // visited是为了防止重复访问，words是为了判断是否在wordList里面
                    // 因为是BFS方法，所以第一次访问到的就是最短路径，因此需要visited记录访问过的节点
                    if(words.find(ncur) != words.end() && visited.find(ncur) == visited.end()){
                        que.push(ncur);
                        visited[ncur] = path_length + 1;
                    }
                }
            }
        }

        return 0;
    }
};

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if(words.find(endWord) == words.end()) return 0;

        unordered_map<string, bool> visited;
        queue<string> que;

        visited[beginWord] = true;
        que.push(beginWord);
        int cnt = 1;

        while(!que.empty()){
            // 方法2，更符合直觉的BFS方法，搜索到就是最小（BFS特性）
            int size = que.size(); // 每次循环次数严格保证是队列长度
            for(int j = 0; j < size; ++j){
                string cur = que.front(); que.pop();
                
                for(int k = 0; k < cur.size(); ++k){
                    string ncur = cur;
                    for(int i = 0; i < 26; ++i){
                        ncur[k] = 'a' + i;
                        if(ncur == endWord) return cnt + 1;
                        if(words.find(ncur) != words.end() && visited.find(ncur) == visited.end()){
                            que.push(ncur);
                            visited[ncur] = true;
                        }
                    }
                }
            }
            cnt++;
        }

        return 0;
    }
};
