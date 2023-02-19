// 自力WA2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        for (int i=0; i<n; ++i) if (lcp[i][i] != n-i) return string("");
        for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) {
            if (lcp[i][j] > n-j) return string("");
            if (lcp[i][j] != lcp[j][i]) return string("");
            if (i-1>=0 && lcp[i-1][j-1]>0 && lcp[i][j]!=lcp[i-1][j-1]-1) return string("");
        }
        string res(n, 'a');
        vector<vector<bool>> cok(n, vector<bool>(26, true));
        for (int i=0; i<n; ++i) {
            res[i] = 'a';
            while (res[i]<=(char)('z') && !cok[i][res[i]-'a']) res[i]++;
            if (res[i] > (char)('z')) return string("");
            for (int j=i+1; j<n; ++j) {
                if (j+lcp[i][j] >= n) continue;
                cok[j+lcp[i][j]][res[i+lcp[i][j]]-'a'] = false;
                res[j+lcp[i][j]] = 'a';
                while (res[j+lcp[i][j]]<=(char)('z') && !cok[j+lcp[i][j]][res[j+lcp[i][j]]-'a']) res[j+lcp[i][j]]++;
                if (res[j+lcp[i][j]] > (char)('z')) return string("");
            }
        }
        return res;
    }
};
