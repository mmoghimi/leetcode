class Solution {
public:
int mem[10000] = {0};
  
int coinChange(vector<int>& coins, int amount) {
  if(mem[amount])
    return mem[amount];
  if(!amount)
    return 0;
  
  int min_amount = INT_MAX;
  for(int i = 0; i < coins.size(); ++i) {
    if(amount>=coins[i] && coinChange(coins, amount-coins[i]) >= 0)
      min_amount = min(min_amount, 1+coinChange(coins, amount-coins[i]));
  }
  return mem[amount] = (min_amount==INT_MAX?-1:min_amount);
}
};
