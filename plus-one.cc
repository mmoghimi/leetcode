class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    vector<int> res;
    int carry_over = 1;
    for(int i = digits.size()-1; i >= 0; --i) {
      res.push_back((digits[i]+carry_over)%10);
      carry_over = (digits[i]+carry_over)/10;
    }
    if(carry_over)
      res.push_back(1);
    reverse(res.begin(), res.end());
    return res;
  }
};
