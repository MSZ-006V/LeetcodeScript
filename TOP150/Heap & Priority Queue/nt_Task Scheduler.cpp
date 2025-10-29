class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // tc O(nlogn) 主要是排序，sc O(1)
        vector<int> count(26, 0);
        for(auto task : tasks){
            count[task - 'A']++;
        }
        sort(count.begin(), count.end());
        
        int max_task = count[25];
        int idle_time = (max_task - 1) * n;
        // 这个方法是贪心法，主要是排序后获取任务数量最多的task，然后根据需要等待的时间，计算出
        // 这个task之间一共有多少个空格，然后从后往前从大往小遍历，利用别的任务填补中间idle的间隔
        // 最后剩下的间隔就是必须只能等待（没有别的任务可以做）的时间，这个时间再加上所有任务的个数
        // 就是总的执行时间
        // 所以最后返回的地方有语句max(0, idle_time)，就是只要一个最大的空闲时间

        for(int i = 24; i > -1; --i){
            idle_time = idle_time - min(max_task - 1, count[i]);
        }
        return max(0, idle_time) + tasks.size();
    }
};
