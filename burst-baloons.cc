class Solution {
public:
vector<vector<int>> mem;
int max(int x, int y) {
  return x>y?x:y;
}
int maxCoins(vector<int>& nums, int st, int en) {
  // cerr << st << " " << en << endl;
  if(st>=en) return 0;
  if(mem[st][en]) return mem[st][en];
  
  int max_coin = 0;
  for(int i = st; i < en; ++i) {
    int coin = nums[i];
    
    if(st>0)
      coin*=nums[st-1];
    
    if(en<nums.size())
      coin*=nums[en];
    
    coin += maxCoins(nums, st, i);
    coin += maxCoins(nums, i+1, en);
    if(coin>max_coin)
      max_coin = coin;
  }
  // cerr << "finished " << st << " " << en << endl;
  return mem[st][en]=max_coin;
}

int maxCoins(vector<int>& nums) {
  mem = vector<vector<int>>(nums.size()+1, vector<int>(nums.size()+1, 0));
  return maxCoins(nums, 0, nums.size());        
}
  
};
