class Solution {
public:
    bool isSubset(vector<int>& a, vector<int>& b) {
        int j = 0;
        int i = 0;
        while(i < a.size()) {
            while(b[j] != a[i]) { 
                j++;
                if(j == b.size())
                    return false;
            }
            i++;
        }

        return i == a.size();
    }

    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        unordered_map<string, int> n2i;
        vector<int> res;

        vector<vector<int>> f(favoriteCompanies.size());
        
        for(int i = 0; i < favoriteCompanies.size(); ++i) {
            for(int j = 0; j < favoriteCompanies[i].size(); ++j) {
                if(n2i.find(favoriteCompanies[i][j]) == n2i.end())
                    n2i[favoriteCompanies[i][j]] = n2i.size();
                f[i].push_back(n2i[favoriteCompanies[i][j]]);
            }
            sort(f[i].begin(), f[i].end());
        }

        for(int i = 0; i < f.size(); ++i) {
            bool has_superset = false;
            for(int j = 0; j < f.size(); ++j) {
                if(i == j)
                    continue;
                if(f[i].size() > f[j].size())
                    continue;
                if(isSubset(f[i], f[j])) {
                    has_superset = true;
                    break;
                }
            }

            if(!has_superset) {
                res.push_back(i);
            }
        }
        return res;
    }
};