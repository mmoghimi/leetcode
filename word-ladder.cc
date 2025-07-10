class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    list<pair<string, int>> queue;
    queue.push_front(make_pair(beginWord, 1));
    
    int answer = 0;
    unordered_set<string> not_visited;
    for(auto word: wordList)
      not_visited.insert(word);
    not_visited.insert(beginWord);
    
    while(!queue.empty()) {
      string w = queue.back().first;
      int d = queue.back().second;
      queue.pop_back();
      
      if(w == endWord) {
        answer = d;
        break;
      }
      
      if(not_visited.find(w) == not_visited.end())
        continue;
      not_visited.erase(w);
      
      for(auto word: not_visited) {
        if(word.length() == w.length()) {
          int diff_count = 0;
          for(int i = 0; i < w.length(); ++i)
            if(w[i]!=word[i])
              diff_count += 1;
          if(diff_count == 1)
            queue.push_front(make_pair(word, d+1));
        }
      }
    }
    return answer;
  }
};
