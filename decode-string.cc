class Solution {
public:

string multiply(string& s, int k) {
  string r = s;
  for (int i = 0; i < k-1; ++i)
    r += s;
  return r;
}
string decodeString(string s) {
  list<string> stack;
  for(int i = 0; i < s.length(); ++i) {
    if(s[i] == ']') {
      string x;
      while (stack.back() != "[") {
        x = stack.back() + x;
        stack.pop_back();
      }
      stack.pop_back();
      
      // cout << x << endl;
      string k_str;
      while(!stack.empty() && stack.back()[0] >= '0' && stack.back()[0] <= '9') {
        k_str = stack.back() + k_str;
        stack.pop_back();
      }
      int k = atoi(k_str.c_str());
      // cout << k_str << " " << k << endl;
      stack.push_back(multiply(x, k));
    } else {
      string x;
      x += s[i];
      stack.push_back(x);
    }
  }
  
  string result;
  while(!stack.empty()) {
    result = stack.back() + result;
    stack.pop_back();
  }
  return result;
}
};
