class Solution {
public:
    int lengthOfLastWord(string s) {
        string w;
        istringstream iss(s);
        while(iss>>w);
        return w.length();
    }
};
