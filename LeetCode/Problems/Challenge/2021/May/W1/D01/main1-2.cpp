#include <bits/stdc++.h>
using namespace std;

// Discuss解2,AC

class WordFilter {
    unordered_map<string, int> ids;
public:
    WordFilter(vector<string>& words) {
        int n = words.size();
        ids = unordered_map<string, int>();
        for (int i=0; i<n; ++i) {
            string ws = words[i];
            int m = ws.length();
            for (int j=1; j<=m; ++j) for (int j2=0; j2<m; ++j2) ids[ws.substr(0,j)+'|'+ws.substr(j2)] = i;
        }
    }
    int f(string prefix, string suffix) {
        return (ids.find(prefix+'|'+suffix)!=ids.end()) ? ids[prefix+'|'+suffix] : -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
