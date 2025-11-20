class Allocator {
private:
    vector<int> cache;

public:
    Allocator(int n): cache(n) {
        
    }
    
    int allocate(int size, int mID) {
        int free = 0;
        for(int i = 0; i < cache.size(); ++i){
            if(cache[i] > 0){
                free = 0;
                continue;
            }
            free++;
            if(free == size){
                fill(cache.begin() + (i - size + 1), cache.begin() + i + 1, mID);
                return i - size + 1;
            }
        }

        return -1;
    }
    
    int freeMemory(int mID) {
        int ans = 0;
        for(int i = 0; i < cache.size(); ++i){
            if(cache[i] == mID){
                ans++;
                cache[i] = 0;
            }
        }
        return ans;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */