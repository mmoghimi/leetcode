class Solution {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    priority_queue<pair<int, int>> q;
    for(auto hk: people)
      q.push(make_pair(-hk[0], -hk[1]));
    
    vector<vector<int>> res(people.size(), vector<int>(2, -1));
    while(!q.empty()) {
      auto person = q.top();
      q.pop();
      int h = -person.first;
      int k = -person.second;
      
      int count = 0;
      for(int i = 0; i < people.size(); ++i) {
        if(res[i][0]==-1 || res[i][0]==h) {
          if(count == k) {
            res[i] = vector<int>{h,k};
            break;
          }
          ++count;
        }
      }
    }
    return res;
  }
};
