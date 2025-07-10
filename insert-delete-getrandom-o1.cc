class RandomizedSet {
public:
    unordered_map<int, int> hash;
    vector<int> vec;
    
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hash.find(val) != hash.end())
            return false;
        
        vec.push_back(val);
        hash[val] = vec.size() - 1;
        
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(hash.find(val) == hash.end())
            return false;
        
        vec[hash[val]] = vec[vec.size()-1];
        hash[vec[vec.size()-1]] = hash[val];
        hash.erase(hash.find(val));
        vec.resize(vec.size()-1);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vec[rand()%vec.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
