class Solution {
public:
  int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    typedef pair<int, int> P;
    vector<vector<P>> adj(N);
    for(int i = 0; i < times.size(); ++i) {
      adj[times[i][0]-1].push_back(P(times[i][1]-1, times[i][2]));
      // adj[times[i][1]-1].push_back(P(times[i][0]-1, times[i][2]));
    }
    
    priority_queue<P> q;
    q.push(P(0, K-1));
    vector<bool> visited(N, false);
    int max_dist = -1;
    while(!q.empty()) {
      int dist = q.top().first;
      int node = q.top().second;
      
      q.pop();
      if(visited[node])
        continue;
      cout << node << endl;
      max_dist = max(max_dist, -dist);
      visited[node] = true;

      for(int i = 0; i < adj[node].size(); ++i)
        q.push(P(dist-adj[node][i].second, adj[node][i].first));
    }

    for(int i = 0; i < N; ++i)
      if(!visited[i])
        return -1;

    return max_dist;
  }
};
