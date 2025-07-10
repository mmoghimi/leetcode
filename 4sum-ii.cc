class Solution {
public:
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
  unordered_map<int, int> ab_sum;
  for(int i = 0; i < A.size(); ++i)
    for(int j = 0; j < B.size(); ++j) {
      int s = A[i]+B[j];
      if(ab_sum.find(s) == ab_sum.end())
        ab_sum[s] = 1;
      else
        ab_sum[s] += 1;
    }
  
  int count = 0;
  for(int i = 0; i < C.size(); ++i)
    for(int j = 0; j < D.size(); ++j) {
      int s = C[i]+D[j];
      if(ab_sum.find(-s)!=ab_sum.end())
        count += ab_sum[-s];
    }
  return count;
}
};
