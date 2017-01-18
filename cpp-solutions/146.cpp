class LRUCache{
private:
    typedef list<int> LI;
    typedef pair<int, LI::iterator> PII;
    typedef unordered_map<int, PII> HIPII;
    LI used;
    HIPII cache;
    int cap;
    void update(HIPII::iterator it){
        int key = it->first;
        used.erase(it->second.second);
        used.push_front(key);
        it->second.second = used.begin();
    }
    
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if(it!=cache.end()){
            update(it);
            return it->second.first;
        }
        return -1;
    }
    
    void set(int key, int value) {
        auto it = cache.find(key);
        if(it!=cache.end()){
            update(it);
        }else{
            if(used.size()==cap){
                cache.erase(used.back());
                used.pop_back();
            }
            used.push_front(key);
        }
        cache[key] = {value, used.begin()};
    }
};