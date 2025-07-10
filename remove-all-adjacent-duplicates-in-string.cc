class Solution {
public:
  string removeDuplicates(string S) {
    if(!S.length())
      return "";
    
    string r;
    list<char> stack;
    
    for(char c: S) {
      if(stack.empty()) {
        stack.push_back(c);
        continue;
      }
      
      if(c == stack.back())
        stack.pop_back();
      else
        stack.push_back(c);
    }
    
    r.reserve(stack.size());
    for(char c: stack)
      r += c;
    
    return r;
  }
};
