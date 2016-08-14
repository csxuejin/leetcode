class RandomizedCollection {
private:
    unordered_multimap<int,int> hash;
    vector<int> vec;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        auto exist = hash.find(val);
        hash.insert({val, vec.size()});
        vec.push_back(val);
        
        return exist==hash.end();
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto it = hash.find(val);
        if(it!=hash.end()){
            int pos = it->second;
            hash.erase(it);    
            vec[pos] = vec.back();
            vec.pop_back();
            
            for(auto tPos=hash.find(vec[pos]); tPos!=hash.end(); tPos++){
                if(tPos->second == vec.size()){
                    hash.erase(tPos);
                    hash.insert({vec[pos], pos});
                    break;
                }
            }
        }
        
        return it!=hash.end();
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return vec[rand()%vec.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
 