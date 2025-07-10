class Solution {
public:
  string removeOuterParentheses(string S) {
    if(!S.length())
      return "";
    
    int num_open = 0;
    int last_pos = 0;
    string out;
    for(int i = 0; i < S.length(); ++i) {
      if(S[i]=='(')
        ++num_open;
      else
        --num_open;
      if(num_open == 0) {
        out += S.substr(last_pos+1, i-last_pos-1);
        last_pos = i+1;
      }
    }
    return out;
  }
};
