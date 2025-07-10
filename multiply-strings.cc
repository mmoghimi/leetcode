class Solution {
public:
  string add(string num1, string num2) {
    string res;
    
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    
    int carry_over = 0;
    for(int i = 0; i < max(num1.length(), num2.length()); ++i) {
      int x = carry_over;
      if(i<num1.length())
        x += num1[i]-'0';
      if(i<num2.length())
        x += num2[i]-'0';
      res += '0'+x%10;
      carry_over = x/10;
    }
    if(carry_over)
      res += carry_over+'0';
    reverse(res.begin(), res.end());
    return res;  
  }
  
  string shift(string num, int k) {
    for(int i = 0; i < k; ++i)
      num += '0';
    return num;
  }
  
  string multiply(string num1, int k) {
    string res;
    int carry_over = 0;
    reverse(num1.begin(), num1.end());
    for(char c: num1) {
      int x = (c-'0')*k+carry_over;
      res += x%10+'0';
      carry_over = x/10;
    }
    if(carry_over)
      res += carry_over+'0';
    
    reverse(res.begin(), res.end());
    return res;
  }
  
  string multiply(string num1, string num2) {
    if(num1 == "0" || num2 == "0")
      return "0";
    
    string res;
    for(int i = 0; i < num1.length(); ++i) {
      string x = multiply(num2, num1[i]-'0');
      x = shift(x, num1.length()-1-i);
      res = add(res, x);
    }
    return res;
  }
};
