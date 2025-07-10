class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        for(int i = 0; i < n; ++i)
            s += '1'+i;

        for(int i = 0; i < k-1; ++i)
            next_permutation(s.begin(), s.end());
        
        return s;
    }
}





class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> f(10, 1);
        for(int i = 2; i < 10; ++i)
            f[i] = f[i-1] * i;

        
        vector<int> remained;
        for(int i = 1; i <= n; ++i)
            remained.push_back(i);

        --k;

        string res;
        int j = n-1;
        while(k) {
            res += '0' + remained[k/f[j]];
            remained.erase(remained.begin() + k/f[j]);
            k = k % f[j];
            --j;
        }
        for(int k: remained)
            res.push_back('0' + k);
        
        return res;
    }
};
