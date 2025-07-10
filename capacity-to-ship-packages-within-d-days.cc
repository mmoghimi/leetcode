class Solution {
public:
  bool isPossible(vector<int>& weights, int D, int capacity) {
    int shipment = 0;
    int d = 1;
    for(int w: weights) {
      if(shipment + w > capacity) {
        ++d;
        shipment = w;
      } else
        shipment += w;
    }
    return D >= d;
  }
  
  int shipWithinDays(vector<int>& weights, int D) {
    int max_capacity = accumulate(weights.begin(), weights.end(), 0);
    int min_capacity = *max_element(weights.begin(), weights.end());
    
    while(max_capacity > min_capacity) {
      int mid = (max_capacity + min_capacity) / 2;
      
      if(isPossible(weights, D, mid))
        max_capacity = mid;
      else
        min_capacity = mid+1;
    }
    
    return max_capacity;
  }
};
