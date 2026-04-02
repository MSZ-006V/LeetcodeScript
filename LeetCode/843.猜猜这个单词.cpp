/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
    //规则匹配引擎，用来进行过滤
    int get_counts(const string&a,const string& b){
        int matches = 0;
        for(int i = 0;i < 6;++i){
            if(a[i] == b[i]) ++matches;
        }
        return matches;
    }
public:
    void findSecretWord(vector<string>& words, Master& master) {
        random_device rd;
        mt19937 gen(rd());

        for(;;){
            uniform_int_distribution<> dist(0,words.size() - 1);
            string guess_word = words[dist(gen)];

            //与目标的匹配程度
            int k = master.guess(guess_word);
            //匹配成功
            if(k == 6) return;

            //匹配失败，则进行过滤
            //guess_word 与 secret满足匹配度为k,
            //则如果有str不满足这个条件，则一定不可能是secret
            vector<string> next_words;
            for(const string& w : words){
                //自身已经确定不是secret,所以忽略
                if(guess_word.compare(w) != 0 && get_counts(guess_word,w) == k){
                    next_words.push_back(w);
                }
            }
            //开启下一轮循环
            words = next_words;
        }
    }
};