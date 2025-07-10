class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream iss(sentence);

        string word;
        int c = 0;
        while(iss >> word) {
            ++ c;
            if(word.length() >= searchWord.length() && searchWord == word.substr(0, searchWord.length()))
                return c;
        }
        return -1;
    }
};