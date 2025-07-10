class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    int num_visited = 0;
    vector<bool> visited(n, false);
    
    list<int> stack;
    stack.push_back(0);
    
    while(stack.size()) {
      int room = stack.back();
      stack.pop_back();
      if(visited[room])
        continue;
      visited[room] = true;
      ++num_visited;
      for(int next_room: rooms[room])
        if(!visited[next_room])
          stack.push_back(next_room);
    }
    return num_visited == n;
  }
};
