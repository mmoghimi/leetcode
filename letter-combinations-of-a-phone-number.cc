class Solution {
public:
    vector<string> letterCombinations(string digits) {
      vector<string> combinations;
      if(!digits.length()) return combinations;
      vector<string> mapping{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
      
      vector<int> state(digits.size(), 0);
      string s;
      for(int i = 0; i < digits.length(); ++i)
          s += mapping[digits[i]-'2'][state[i]];
        combinations.push_back(s);
      
      while(true) {
        int i = digits.size()-1;
        while(true) {
          ++state[i];
          if(state[i] < mapping[digits[i]-'2'].length())
            break;
          state[i] = 0;
          --i;
          if(i < 0)
            return combinations;
        }
        string s;
        for(i = 0; i < digits.length(); ++i)
          s += mapping[digits[i]-'2'][state[i]];
        combinations.push_back(s);
      }
      
      return combinations;
    }
};
