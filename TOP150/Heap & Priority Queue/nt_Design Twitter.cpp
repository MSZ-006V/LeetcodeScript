class Twitter {
    private:
        int clock;
        unordered_map<int, vector<pair<int, int>>> user_tweet;
        unordered_map<int, vector<int>> user_follow;
    public:
        Twitter(): clock(0) {
            
        }
        
        void postTweet(int userId, int tweetId) {
            user_tweet[userId].push_back({tweetId, clock});
            clock++;
        }
        
        vector<int> getNewsFeed(int userId) {
            auto cmp = [](auto a, auto b){
                return a.second < b.second;
            };
            priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
            for(auto message : user_tweet[userId]){
                pq.push(message);
            }
            for(auto user : user_follow[userId]){
                for(auto message : user_tweet[user]){
                    pq.push(message);
                }
            }
    
            int num = 10;
            vector<int> res;
            while(!pq.empty() && num-- > 0){
                res.push_back(pq.top().first); pq.pop();
            }
    
            return res;
        }
        
        void follow(int followerId, int followeeId) {
            if(followerId == followeeId) return;
            if(find(user_follow[followerId].begin(), user_follow[followerId].end(), followeeId) != user_follow[followerId].end()){
                return;
            }
            user_follow[followerId].push_back(followeeId);
        }
        
        void unfollow(int followerId, int followeeId) {
            auto it = find(user_follow[followerId].begin(), user_follow[followerId].end(), followeeId);
            if(it != user_follow[followerId].end()){
                user_follow[followerId].erase(it);
            }
        }
    };
    