#include <bits/stdc++.h>
using namespace std;

// 自力AC

using ll = long long;
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        vector<string> strs = words, rstrs = strs;
        for (int i=0; i<n; ++i) reverse(rstrs[i].begin(), rstrs[i].end());
        unordered_map<string, int> ids, rids;
        for (int i=0; i<n; ++i) {
            ids[strs[i]] = i;
            rids[rstrs[i]] = i;
        }
        set<vector<int>> rst;
        for (int i0=0; i0<2; ++i0) {
            for (int i=0; i<n; ++i) {
                int m = strs[i].length();
                if (rids.find(strs[i])!=rids.end() && rids[strs[i]]!=i) {
                    if (i0 == 0) rst.insert(vector<int>({ i, rids[strs[i]] }));
                    else rst.insert(vector<int>({ rids[strs[i]], i }));
                }
                for (int j=m-1; j>=(m-1)/2; --j) {
                    if (2*j-m+1<m && 2*j-m+1>=0) {
                        bool ok = true;
                        for (int j2=1; j+j2<m; ++j2) if (strs[i][j+j2] != strs[i][j-j2]) {
                            ok = false;
                            break;
                        }
                        if (ok) {
                            if (rids.find(strs[i].substr(0, 2*j-m+1))!=rids.end() && rids[strs[i].substr(0, 2*j-m+1)]!=i) {
                                if (i0 == 0) rst.insert(vector<int>({ i, rids[strs[i].substr(0, 2*j-m+1)] }));
                                else rst.insert(vector<int>({ rids[strs[i].substr(0, 2*j-m+1)], i }));
                            }
                        }
                    }
                    if (j+1<m && 2*j-m+2<m && 2*j-m+2>=0 && strs[i][j]==strs[i][j+1]) {
                        bool ok2 = true;
                        for (int j2=1; j+j2+1<m; ++j2) if (strs[i][j+j2+1] != strs[i][j-j2]) {
                            ok2 = false;
                            break;
                        }
                        if (ok2) {
                            if (rids.find(strs[i].substr(0, 2*j-m+2))!=rids.end() && rids[strs[i].substr(0, 2*j-m+2)]!=i) {
                                if (i0 == 0) rst.insert(vector<int>({ i, rids[strs[i].substr(0, 2*j-m+2)] }));
                                else rst.insert(vector<int>({ rids[strs[i].substr(0, 2*j-m+2)], i }));
                            }
                        }
                    }
                }
            }
            swap(strs, rstrs);
            swap(ids, rids);
        }
        vector<vector<int>> res;
        if (!rst.empty()) res.assign(rst.begin(), rst.end());
        return res;
    }
};
