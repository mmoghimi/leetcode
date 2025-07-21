class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> max_profit(k+1, vector<vector<int>>(n, vector<int>(2)));
        //max_profit[j][i][0] == max profit using j transactions and up to and including prices i when not holding anything
        //max_profit[i][j][1] == is same as above while having bought stock
        for(int j = 0; j <= k; ++j)
            max_profit[j][0][1] -= prices[0];
        for(int i = 1; i < n; ++i) {
            for(int j = 1; j <= k; ++j) {
                max_profit[j][i][0] = max(max_profit[j][i-1][0], max_profit[j][i-1][1] + prices[i]);
                max_profit[j][i][1] = max(max_profit[j][i-1][1], max_profit[j-1][i-1][0] - prices[i]);
            }
        }

        int res = 0;
        for(int j = 0; j <= k; ++j)
            res = max(res, max_profit[j][n-1][0]);
        return res;
    }
};