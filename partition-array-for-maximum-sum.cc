class Solution {
public:
  vector<int> mem;
  
  int maxSumAfterPartitioning(vector<int>& A, int n, int K) {
    if(mem[n] > INT_MIN)
      return mem[n];
    
    int max_sum = INT_MIN;
    int max_val = A[n-1];
    for(int i = 1; i <= K && n-i>=0; ++i) {
      if(A[n-i] > max_val)
        max_val = A[n-i];
      int new_sum = maxSumAfterPartitioning(A, n-i, K)+max_val*i;
      if(new_sum > max_sum)
        max_sum = new_sum;
    }
    
    return mem[n] = max_sum;
  }
  
  int maxSumAfterPartitioning(vector<int>& A, int K) {
    mem = vector<int>(A.size()+1, INT_MIN);
    mem[0] = 0;
    return maxSumAfterPartitioning(A, A.size(), K);
  }
};
