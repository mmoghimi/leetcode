class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odds = 0;
        int evens = 0;

        for(int x: position) {
            if(x%2==0)
                ++evens;
            else
                ++odds;
        }
        return min(evens, odds);
    }
};
