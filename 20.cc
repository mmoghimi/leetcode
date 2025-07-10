class Solution {
public:
    bool isValid(string s) {
      list<char> stack;
      map<char, char> match;
      match[')'] = '(';
      match['}'] = '{';
      match[']'] = '[';
      for(int i = 0; i < s.length(); ++i) {
        if(match.find(s[i]) == match.end()) {
          stack.push_back(s[i]);
          continue;
        }
        if(stack.empty() || match[s[i]] != stack.back()) {
          return false;
        } else{
          stack.pop_back();
        }
      }
      return stack.empty();
    }
};
