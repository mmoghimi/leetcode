class Solution {
public:
int minPathSum(vector<vector<int>>& grid) {
  if(!grid.size())
    return 0;
  if(!grid[0].size())
    return 0;
  vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size()));
  for(int i = 0; i < grid.size(); ++i)
    for(int j = 0; j < grid[i].size(); ++j) {
      if(i == 0 && j == 0) {
        dist[0][0] = grid[0][0];
        continue;
      }
      int min_dist = 10000;
      if(i > 0)
        min_dist = min(min_dist, dist[i-1][j] + grid[i][j]);
      if(j > 0)
        min_dist = min(min_dist, dist[i][j-1] + grid[i][j]);
      
      dist[i][j] = min_dist;
    }
  return dist[grid.size()-1][grid[0].size()-1];
}
};
