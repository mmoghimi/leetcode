class Solution {
public:

int gcd(int x, int y) {
    if(x > y) {
        int t = x;
        x = y;
        y = t;
    }
    if(!x && !y)
        return 1;
    while(x && y) {
        int t = x;
        x = y%x;
        y = t;
    }
    return y;
}

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;  
    }
};
    
int maxPoints(vector<vector<int>>& points) {
  if(points.size() <= 2)
      return points.size();
    
  int max_res = 0;
  for(auto orig: points) {
     typedef pair<int, int> P;
     unordered_map<P, int, pair_hash> hash_map;
     int same_point = 0;
     for(auto p: points) {
        int x = p[0] - orig[0];
        int y = p[1] - orig[1];

         if(x == 0 && y == 0)
            ++same_point;
         else {
             // int g = gcd(abs(x), abs(y));
             int g = std::gcd(x, y);
             x /= g;
             y /= g;
             P dir = make_pair(x, y);
             if(hash_map.find(dir) == hash_map.end())
               hash_map[dir] = 1;
             else   
               hash_map[dir] += 1;
         }
     }
     max_res = max(max_res, same_point);
     for(auto it: hash_map) {
        max_res = max(max_res, same_point + it.second);
     }
  }
  return max_res;
}
};
