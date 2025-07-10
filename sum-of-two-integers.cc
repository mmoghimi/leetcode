class Solution {
public:
int getSum(int a, int b) {
  int c = 0;
  int carry_over = 0;
  for(int i = 0; i < 8*sizeof(a); ++i) {
    int a_bit = (a >> i)&1;
    int b_bit = (b >> i)&1;
    if(!carry_over) {
      c = c | ((a_bit^b_bit) << i);
      carry_over = (a_bit&b_bit);
    } else {
      c = c | (!(a_bit^b_bit) << i);
      carry_over = (a_bit|b_bit);
    }
  }
  return c;
}
};
