class Solution {
public:
int search(vector<int>& nums, int target) {
  if(!nums.size())
    return -1;
  
  uint16_t st = 0;
  uint16_t en = nums.size()-1;
  uint16_t mid;
  while(en>st+1) {
    mid = (st+en)/2;
    // cout << st << " " << mid << " " << en << endl;
    if(nums[mid] < nums[0])
      en = mid;  
    else
      st = mid;
  }
  // cout << st << " " << mid << " " << en << endl;
  uint16_t pivot = 0;
  if((nums[st] < nums[0]))
    pivot = st;
  else if(nums[en] < nums[0])
    pivot = en;

  // cout << nums[pivot] << endl;
  
  st = 0;
  en = nums.size()-1;
  while(en>st+1) {
    // cout << st << " " << mid << " " << en << endl;
    
    mid = (st+en)/2;
    if(nums[(mid+pivot)%nums.size()] < target)
      st = mid;  
    else
      en = mid;
  }
  // cout << st << " " << mid << " " << en << endl;
  
  if(nums[(st+pivot)%nums.size()] == target)
    return (st+pivot)%nums.size();
  if(nums[(en+pivot)%nums.size()] == target)
    return (en+pivot)%nums.size();
  return -1;
}
};
