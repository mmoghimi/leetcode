class Solution {
public:
vector<vector<int>> mem;
int minDistance(string word1, string word2) {
  mem = vector<vector<int>>(word1.length()+1, vector<int>(word2.length()+1, -1));
  return minDistanceTillMN(word1, word2, word1.length(), word2.length());  
}
int min(int x, int y) {
  return x>y?y:x;
}
int minDistanceTillMN(string word1, string word2, int m, int n) {
  if(mem[m][n]>=0) return mem[m][n];
  if(n == 0) return m;
  if(m == 0) return n;
  
  int min_dist = INT_MAX;
  int dist;
  if(word1[m-1] == word2[n-1]) {
    dist = minDistanceTillMN(word1, word2, m-1, n-1);
    min_dist = min(min_dist, dist);
  } else {
    dist = minDistanceTillMN(word1, word2, m-1, n) + 1;
    min_dist = min(min_dist, dist);
    dist = minDistanceTillMN(word1, word2, m, n-1) + 1;
    min_dist = min(min_dist, dist);
    dist = minDistanceTillMN(word1, word2, m-1, n-1) + 1;
    min_dist = min(min_dist, dist);
  }
    
  return mem[m][n]=min_dist;
}
};
