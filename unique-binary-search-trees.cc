class Solution {
public:
int mem[1000] = {0};
int numTrees(int n) {
  if(n <= 1)
    return 1;
  
  if(mem[n])
    return mem[n];
  
  int solution = 0;
  for(int i = 0; i < n; ++i)
    solution += numTrees(i) * numTrees(n-1-i);
  return mem[n] = solution;
}
};
