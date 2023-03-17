// 解説AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size(), aid = 0;
        vector<int> alst(n, -1);
        for (int i=0; i<n; ++i) if (alst[i] == -1) {
            alst[i] = aid;
            for (int j=i+1; j<n; ++j) if (lcp[i][j] > 0) alst[j] = aid;
            ++aid;
        }
        if (aid > 26) return string("");
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
            if (lcp[i][j] > 0) {
                if (alst[i] != alst[j]) return string("");
                if ((i+1>=n || j+1>=n) && lcp[i][j]!=1) return string("");
                if (i+1<n && j+1<n && lcp[i][j]!=lcp[i+1][j+1]+1) return string("");
            }
            else {
                if (alst[i] == alst[j]) return string("");
            }
        }
        string res(n, 'a');
        for (int i=0; i<n; ++i) res[i] += alst[i];
        return res;
    }
};
