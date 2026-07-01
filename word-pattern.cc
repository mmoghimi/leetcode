class Solution {
public:
    int countWords(string s) {
        istringstream iss(s);
        int count = 0;
        string word;
        while(iss >> word)
            ++count;
        return count;
    }

    bool wordPattern(string pattern, string s) {
        if(countWords(s) != pattern.length())
            return false;

        istringstream iss(s);
        string word;
        vector<string> m(256, "");

        for(char c: pattern) {
            iss >> word;
            if(m[c] != "") {
                if (m[c] != word)
                    return false;
            } else {
                m[c] = word;
            }
        }

        map<string, char> mm;

        istringstream jss(s);
        for(char c: pattern) {
            jss >> word;

            if(mm.find(word) != mm.end()) {
                if (mm[word] != c)
                    return false;
            } else {
                mm[word] = c;
            }
        }

        return true;
    }
};

