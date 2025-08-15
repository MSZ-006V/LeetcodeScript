class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // tc O(nlogk), sc O(n)
        unordered_map<int, int> ht;
        for(auto& num : nums){
            ht[num]++;
        }

        auto cmp = [](auto a, auto b){
            return a.second > b.second;
        };

        priority_queue<std::pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for(auto& p : ht){
            pq.push(p);
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top().first);
            pq.pop();
        }

        return result;
    }
};

// 可以使用bucket sort，先对每个数统计个数，然后按照个数把每个数放到不同的桶里面
// 每个不同的桶代表着出现次数的不同
// 注意bucket这个桶长度应该是num.size() + 1，因为一个数最多可以出现num.size()次，所以桶的最大出现次数应该是num.size()
// 最后遍历的时候i可以大于0，因为等于0相当于出现次数是0，要这个结果没用
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ht;
        vector<vector<int>> bucket(nums.size() + 1, vector<int>(0));

        for(auto& num : nums){
            ht[num]++;
        }
        for(auto& p : ht){
            bucket[p.second].push_back(p.first);
        }

        vector<int> result;

        for(int i = nums.size(); i > 0; --i){
            for(auto num : bucket[i]){
                result.push_back(num);
                if(result.size() == k) return result;
            }
        }
        
        return result;
    }
};

