// 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<vector<bool>> g(n, vector<bool>(n));
        for (int i=0; i<n; ++i) {
            string si = words[i];
            sort(si.begin(), si.end());
            for (int j=i+1; j<n; ++j) {
                string sj = words[j];
                sort(sj.begin(), sj.end());
                if (si == sj) g[i][j] = g[j][i] = true;
            }
        }
        set<int> ids;
        for (int i=0; i<n; ++i) ids.insert(i);
        for (auto itr=ids.begin(); itr!=ids.end(); ++itr) {
            while (next(itr)!=ids.end() && g[*itr][*next(itr)]) ids.erase(*next(itr));
        }
        vector<string> res;
        for (int id : ids) res.push_back(words[id]);
        return res;
    }
};
