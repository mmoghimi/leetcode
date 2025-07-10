class Solution {
public:
    string makeLine(vector<string>& words, bool last_line, int maxWidth) {
        string line;
        if(last_line || words.size() == 1) {
            for(string word: words) {
                line += word + ' ';
            }
            for(int i = 0; i < maxWidth; ++i)
                line += ' ';
            return line.substr(0, maxWidth);
        }

        int total_length = 0;
        for(string word: words)
            total_length += word.length();
        
        for(int i = 0; i < words.size(); ++i ) {
            int num_spaces = (maxWidth-total_length) / (words.size()-1) 
             + (i< (maxWidth-total_length) % (words.size()-1) ? 1 : 0);

            line += words[i];
            if(i < words.size() - 1)
                for(int j = 0; j < num_spaces; ++j)
                    line += ' ';
            
        }
        return line;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> lines;

        vector<string> last_set;
        int total_length = 0;
        for(int i = 0; i < words.size(); ++i) {
            string word = words[i];

            if(total_length + word.length() > maxWidth) {
                lines.push_back(makeLine(last_set, false, maxWidth));
                total_length = word.length() + 1;
                last_set = vector<string>(1, word);
            } else if (total_length + word.length() == maxWidth) {
                last_set.push_back(word);
                lines.push_back(makeLine(last_set, false, maxWidth));
                total_length = 0;
                last_set.clear();
            } else {
                last_set.push_back(word);
                total_length += word.length() + 1;
            }
        }
        if(last_set.size())
            lines.push_back(makeLine(last_set, true, maxWidth));
        
        return lines;
    }
};