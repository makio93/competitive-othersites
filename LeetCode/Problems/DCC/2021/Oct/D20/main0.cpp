#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        vector<string> svec;
        int lid = -1;
        for (int i=0; i<n; ++i) {
            if (s[i]!=' ' && lid==-1) lid = i;
            else if (s[i]==' ' && lid!=-1) {
                svec.push_back(s.substr(lid, i-lid));
                lid = -1;
            }
        }
        if (s[n-1] != ' ') svec.push_back(s.substr(lid, n-lid));
        reverse(svec.begin(), svec.end());
        string t;
        int m = svec.size();
        for (int i=0; i<m; ++i) {
            t += svec[i];
            if (i < m-1) t += ' ';
        }
        return t;
    }
};
