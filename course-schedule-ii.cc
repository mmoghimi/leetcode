class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prereqs) {
    unordered_set<int> sat_set;
    vector<int> order;
    vector<int> indeg(numCourses, 0);
    for(int j = 0; j < prereqs.size(); ++j)
        ++ indeg[prereqs[j][0]];
    
    for(int i = 0; i < numCourses; ++i)
      if(indeg[i] == 0)
        sat_set.insert(i);

    while(!sat_set.empty()) {
      int course = *(sat_set.begin());
      sat_set.erase(sat_set.begin());
      order.push_back(course);
      
      for(int i = 0; i < prereqs.size(); ++i)
        if(prereqs[i][1] == course) {
          --indeg[prereqs[i][0]];
          if(indeg[prereqs[i][0]] == 0)
            sat_set.insert(prereqs[i][0]);
        }
    }
    if(order.size() != numCourses)
      return vector<int>();
    
    return order;
  }
};
