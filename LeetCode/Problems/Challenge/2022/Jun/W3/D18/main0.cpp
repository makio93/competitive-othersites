// 自力AC

#include <bits/stdc++.h>
using namespace std;

class WordFilter {
    unordered_map<string, int> dict;
public:
    WordFilter(vector<string>& words) {
        int n = words.size();
        for (int i=0; i<n; ++i) {
            int len = words[i].length();
            for (int l=0; l<len; ++l) for (int r=len-1; r>=0; --r) {
                string tmp = words[i].substr(0, l+1) + "|" + words[i].substr(r);
                dict[tmp] = max(dict[tmp], i);
            }
        }
    }
    int f(string prefix, string suffix) {
        string tmp = prefix + "|" + suffix;
        if (dict.find(tmp) != dict.end()) return dict[tmp];
        else return -1;
    }
};
