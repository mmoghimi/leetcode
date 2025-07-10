class Solution {
public:
string MakeString(vector<int>& v) {
  string s;
  for(int i = 0; i < v.size(); ++i)
    s += ((v[i]==1)?"(":")");
  return s;
}
vector<string> generateParenthesis(int n) {
  vector<int> vec(2*n, -1);
  for(int i = n; i < 2*n; ++i)
    vec[i] = 1;
  vector<string> valid_set;
  do {
    int num_open = 0;
    for(int i = 0; i < 2*n; ++i) {
      num_open += vec[i];
      if(num_open<0)
        break;
    }
    if(!num_open)
      valid_set.push_back(MakeString(vec));
  } while(next_permutation(vec.begin(), vec.end()));
  return valid_set;
}
};
