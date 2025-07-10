class Solution {
public:
vector<int> countBits(int num) {
  vector<int> num_bits(num+1);
  for(int i = 0; i <= num; ++i)
    num_bits[i] = num_bits[i>>1] + (i&1);
  return num_bits;
}
};
