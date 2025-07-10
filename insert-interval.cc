class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();
        int i = 0;

        while(i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            ++i;
        }
        
        int s = newInterval[0];
        int e = newInterval[1];
        while(i < n && intervals[i][0] <= newInterval[1]) {
            s = min(s, intervals[i][0]);
            e = max(e, intervals[i][1]);
            ++i;
        }
        vector<int> merged;
        merged.push_back(s);
        merged.push_back(e);
        res.push_back(merged);

        while(i < intervals.size()) {
            res.push_back(intervals[i]);
            ++i;
        }
    
        return res;
    }
};