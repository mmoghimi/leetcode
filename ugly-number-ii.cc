class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<int64_t> q;
        q.push(-1);
        unordered_set<int64_t> s;

        for(int i = 0; i < n; ++i) {
            if(i == n-1)
                return -q.top();

            auto x = q.top();
            q.pop();
            
            if(s.find(x*2) == s.end()) {
                s.insert(x*2);
                q.push(x*2);
            }

            if(s.find(x*3) == s.end()) {
                s.insert(x*3);
                q.push(x*3);
            }

            if(s.find(x*5) == s.end()) {
                s.insert(x*5);
                q.push(x*5);
            }

        }

        return 0;
    }
};
