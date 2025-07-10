class Solution {
public:
  bool colorGraph(vector<vector<int>>& graph, vector<bool>& skip) {
    int start = -1;
    for(int i = 0; i < graph.size(); ++i)
      if(!skip[i]) {
        start = i;
        break;
      }
    
    if(start == -1)
      return false;
    
    vector<int> node_list;
    vector<int> visited(graph.size(), 0);
    typedef pair<int, int> P;
    list<P> stack;
    stack.push_back(P(start, 1));
    
    while(!stack.empty()) {
    	int node = stack.back().first;
    	int color = stack.back().second;
    	stack.pop_back();
    	if(visited[node])
    		continue;
      // cout << "XXX" << " " << node << " " << color << endl;
    	visited[node] = color;
    	for(int i = 0; i < graph[node].size(); ++i)
    		if(!visited[graph[node][i]])
    			stack.push_back(P(graph[node][i], -color));
    }
    
    // for(int i = 0; i < graph.size(); ++i)
    //   cout << i << " " << visited[i] << endl;
        
    for(int i = 0; i < graph.size(); ++i)
      if(visited[i]) {
        for(int j = 0; j < graph[i].size(); ++j)
          if(visited[i] == visited[graph[i][j]])
            return false;
      }
  
    // cout << "hereerelkj;d" << endl;
    for(int i = 0; i < graph.size(); ++i)
      if(visited[i])
        skip[i] = true;

    return true;
  }
  
  bool isBipartite(vector<vector<int>>& graph) {
  	vector<bool> skip(graph.size(), false);
    while(colorGraph(graph, skip)) {}
    
    // for(int i = 0; i < graph.size(); ++i)
    //     cout << "S" << i << " " << skip[i] << endl;;

    return skip == vector<bool>(skip.size(), true);
  }
};
