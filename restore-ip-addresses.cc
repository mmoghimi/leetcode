class Solution {
public:
    bool isValid(string& s, int start, int len) {
        if(len == 0 || len > 3)
            return false;
        
        if(s[start] == '0')
            return len == 1;

        if(len <= 2)
            return true;
        
        int x = (s[start]-'0')*100 + (s[start+1]-'0')*10 + (s[start+2]-'0');
        return x <= 255;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;

        int n = s.length();
        for(int i = 0; i < n && i < 3; ++i) {
            if(!isValid(s, 0, i+1))
                continue;
            
            for(int j = i+1; j < n && j < i+4; ++j) {
                if(!isValid(s, i+1, j-i))
                    continue;
                    
                for(int k = j+1; k < n && k < j+4; ++k) {
                    if(!isValid(s, j+1, k-j) || !isValid(s, k+1, n-k-1))
                        continue;

                    string ii = s.substr(0, i+1);
                    string jj = s.substr(i+1, j-i);
                    string kk = s.substr(j+1, k-j);
                    string ll = s.substr(k+1, n-k);

                    res.push_back(ii + "." + jj + "." + kk + "." + ll);
                }
            }
        }
        return res;
    }
};
