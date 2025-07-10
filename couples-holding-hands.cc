class Solution {
public:
    inline int partner(int x) {
        return x%2?x-1:x+1;
    }

    int minSwapsCouples(vector<int>& row) {
        int n = row.size()/2;
        vector<int> reverse_index(2*n);
        for(int i = 0; i < 2*n; ++i)
            reverse_index[row[i]] = i;

        vector<bool> done(2*n, false);
        int res = n;
        for(int i = 0; i < 2*n; i+=2) {
            if(done[row[i]])
                continue;

            --res;
            
            list<int> q;
            q.push_back(row[i]);
            while(!q.empty()) {
                int c = q.back();
                q.pop_back();

                done[c] = true;

                if(!done[partner(c)]) {
                    q.push_back(partner(c));
                }
                if(!done[row[partner(reverse_index[c])]]) {
                    q.push_back(row[partner(reverse_index[c])]);
                }
            }
        }

        return res;
    }
};