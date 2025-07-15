class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> max_profit(n);
        int min_so_far = prices[0];
        for(int i = 1; i < prices.size(); ++i) {
            min_so_far = min(min_so_far, prices[i]);
            max_profit[i] = max(max_profit[i-1], prices[i] - min_so_far);
        }

        int res = max_profit[n-1]; // this is max_profit with one transaction
        int max_so_far = prices[n-1];
        int right_max_profit = 0;
        for(int i = n-2; i >= 1; --i) {
            max_so_far = max(max_so_far, prices[i]);
            right_max_profit = max(right_max_profit, max_so_far - prices[i]);
            res = max(res, right_max_profit + max_profit[i-1]);
        }
        return res;
    }
};