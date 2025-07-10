class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> num_set;
        for(int x: nums) {
            if(num_set.find(x) != num_set.end())
                return true;
            num_set.insert(x);
        }
        return false;
    }
};
