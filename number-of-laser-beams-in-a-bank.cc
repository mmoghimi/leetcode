class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> counts;
        for(string s: bank) {
            int count = 0;
            for(char i: s)
            	if(i == '1')
            	    ++count;
            if(count)
                counts.push_back(count);
        }
        if(counts.size() <= 1)
        	return 0;
        
        int res = 0;
        for(int i = 0; i < counts.size()-1; ++i)
            res += counts[i] * counts[i+1];
        return res;
    }
};