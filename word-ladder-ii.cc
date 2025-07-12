
class Solution {
public:
    inline bool is_neighbor(string& s, string& r) {
        int mismatch = 0;
        for(int j = 0; j < r.length(); ++j)
            if(r[j] != s[j])
                ++mismatch;
        return mismatch == 1;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int endWord_index = -1;
        for(int i = 0; i < wordList.size(); ++i)
            if(endWord == wordList[i]) {
                endWord_index = i;
            }
        if(endWord_index == -1)
            return {};

        vector<vector<int>> neighbors(wordList.size());
        for(int i = 0; i < wordList.size(); ++i) {
            for(int j = i+1; j < wordList.size(); ++j) {
                if(is_neighbor(wordList[i], wordList[j])) {
                    neighbors[j].push_back(i);
                    neighbors[i].push_back(j);
                }
            }
        }

        vector<vector<int>> parents(wordList.size());

        list<int> q;
        vector<int> visited(wordList.size(), -1);
        for(int i = 0; i < wordList.size(); ++i) {
            if(is_neighbor(beginWord, wordList[i])) {
                visited[i] = 1;
                q.push_back(i);
            }
        }

        vector<vector<string>> res;
        while(!q.empty()) {
            int node = q.front();
            q.pop_front();
    
            for(int i: neighbors[node]) {
                if(visited[i] == -1) {
                    visited[i] = visited[node] + 1;
                    q.push_back(i);
                }
            }
        }

        list<vector<int>> paths;
        paths.push_back({endWord_index});
        while(!paths.empty()) {
            vector<int> path = paths.front();
            paths.pop_front();

            if(visited[path.back()] == 1) {
                vector<string> sol = {beginWord};
                reverse(path.begin(), path.end());
                for(int i: path)
                    sol.push_back(wordList[i]);
                res.push_back(sol);
                continue;
            }

            for(int i: neighbors[path.back()]) {
                if(visited[i] == visited[path.back()] - 1) {
                    vector<int> new_path = path;
                    new_path.push_back(i);
                    paths.push_back(new_path);
                }
            }
        }
        return res;      
    }
};