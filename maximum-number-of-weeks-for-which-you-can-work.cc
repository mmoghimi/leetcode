class Solution {
public:
    long long numberOfWeeks(vector<int>& m) {
        long long sum = 0;
        int mx = 0;

        for(int x: m) {
            if (mx < x)
                mx = x;
            sum += x;
        }

        if (mx <= sum-mx+1)
            return sum;
        
        return (sum-mx)* 2 + 1;
    }
};