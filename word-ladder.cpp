#include <unordered_set>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <list>
using namespace std;
class Solution {
public:
  bool changable(string a, string b) {
    if(a.length() != b.length())
      return false;

    int diff_count = 0;
    for(int i = 0; i < a.length(); ++i) {
      if(a[i]!=b[i])
        diff_count += 1;
      if(diff_count > 1)
        return false;
    }
    return diff_count == 1;
  }
  
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
      cerr << "$$$" << w << " " << d << " " << endWord << endl;
      
      if(w == endWord) {
        cerr << "heresdfdsfds " << endl;
        answer = d;
        break;
      }
      // cerr << "###" << w << " " << d << " " << endWord << endl;
      
      if(not_visited.find(w) == not_visited.end())
        continue;
      not_visited.erase(w);

      cout << "here" << endl;
      
      // for(string word: wordList)
      // for(int j = 0; j < wordList.size(); ++j) {
      //   string word = wordList[j];
      for(auto word: not_visited) {
        cout << "@@@@@@@@@@@@" << word << endl;
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
    
    // cerr << "sdfds" << endl;
    return answer;
  }
};

int main(int argc, char const *argv[])
{
  Solution s;
  std::vector<string> v{"hot","dot","dog","lot","log","cog"};
  cout << s.ladderLength("hit", "cog", v) << endl;
  return 0;
}