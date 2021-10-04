class RandomizedSet {
private:
    unordered_map<int, int> hash;
    vector<int> vec;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hash.find(val)==hash.end()){
            vec.push_back(val);
            hash[val] = vec.size()-1;
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(hash.find(val)!=hash.end()){
            int index = hash[val];
            vec[index] = vec.back();
            hash[vec.back()] = index;
            vec.erase(vec.end()-1);
            hash.erase(val);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vec[rand()%vec.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */