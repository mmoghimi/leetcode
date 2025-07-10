class Solution {
public:
    int candy(std::vector<int>& ratings) {
        int n = ratings.size();
        if (n == 1) {
            return 1;
        }

        vector<int> candies(n, 1);

        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
        }

        int total_candies = 0;
        for (int candy_count : candies) {
            total_candies += candy_count;
        }
        
        return total_candies;
    }
};
