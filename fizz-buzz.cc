class Solution {
public:
  vector<string> fizzBuzz(int n) {
    vector<string> res;
    for(int i = 1; i <= n; ++i) {
      ostringstream oss;
      oss << i;
      if(i%15 == 0)
        res.push_back("FizzBuzz");
      else if(i%5 == 0)
        res.push_back("Buzz");
      else if(i%3 == 0)
        res.push_back("Fizz");
      else
        res.push_back(oss.str());
    }
    return res;
  }
};
