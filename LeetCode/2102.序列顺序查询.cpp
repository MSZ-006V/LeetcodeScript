class SORTracker {
public:
    // 对顶堆
    // 通过在最大堆插入负数，同时控制堆的大小，来维护第k大的数
    // 堆 -10， -20， -30，
    // 降序排序，维护第k大的数
    // {参数一小,参数二大}
    priority_queue<pair<int, string>> left;
    // {参数一大,参数二小}
    priority_queue<pair<int, string>, vector<pair<int, string>>,greater<pair<int, string>>> right;
    int index = 1;
    SORTracker() {}

    void add(string name, int score) {
        // 维护第index大的数
        if (left.size() < index) {
            right.emplace(-score, name);
            left.emplace(right.top());
            right.pop();
        } else {
            left.emplace(-score, name);
            right.emplace(left.top());
            left.pop();
        }
    }

    string get() {
        string name = left.top().second;
        if (!right.empty()) {
            left.emplace(right.top());
            right.pop();
        }
        // 下一次查询
        index++;
        return name;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */