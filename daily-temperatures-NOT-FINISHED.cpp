class Solution {
public:
vector<int> dailyTemperatures(vector<int>& T) {
  if(T.size() == 1)
  	return vector<int>(1);

  vector<int> dist_to_max(T.size(), -1);
  vector<int> max_from_index(T.size(), 0);

  max_from_index[T.size()-1] = T[T.size()-1];
  for(int i = T.size()-2; i >= 0; --i) {
  	max_from_index[i] = max(max_from_index[i+1], T[i]);
  }

  for(int i = 0; i < T.size()-1; ++i) {
  	// do binary search on max_from_index[i+1, T.size()-1]
  	int start = i+1;
  	int end = T.size()-1;
  	int mid;
    cout << "hji" << endl;

  	while(end>start+1) {
      cout << start << " " << end << endl;
      mid = (start + end) / 2;
      if(max_from_index[mid] > T[i])
        end = mid;
      else
        start = mid;
  	}
    cout << "bye" << endl;
    cout << start << " " << end << endl;
    for (int j = end; j >= start; --j)
  		if(T[j] > T[i])
  			dist_to_max[i] = j-i;
  }
  return dist_to_max;
}
};