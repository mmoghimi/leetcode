class RandomizedCollection {
public:
    unordered_map <int, unordered_set<int>> h;
    vector<int> v;
    RandomizedCollection() {
    }
    void printAll() {
        for(int x: v)
            cout << x << " ";
        cout << endl;
    }
    bool insert(int val) {
        if(h.find(val)==h.end()) {
            h[val].insert(v.size());
            v.push_back(val);
            return true;
        }
        h[val].insert(v.size());
        v.push_back(val);
        return false;
    }
    
    bool remove(int val) {
        if(h.find(val)==h.end()) {
            return false;
        }
        
        int index = *h[val].begin();
        if (index == v.size()-1) {
            h[val].erase(h[val].begin());
            v.pop_back();
        } else {
            h[val].erase(h[val].begin());
            v[index] = v[v.size()-1];
            int x = v[v.size()-1];
            h[x].erase(h[x].find(v.size()-1));
            h[x].insert(index);
            v.pop_back();
        }

        if(!h[val].size()) {
            h.erase(h.find(val));
        }
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */