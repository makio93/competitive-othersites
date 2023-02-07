#include <bits/stdc++.h>
using namespace std;

// 自力TLE

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        vector<pair<int, int>> lds(n);
        for (int i=0; i<n; ++i) lds[i] = { courses[i][1], courses[i][0] };
        sort(lds.begin(), lds.end());
        map<int, int> st;
        st[0] = 0;
        for (int i=0; i<n; ++i) {
            map<int, int> nst;
            for (auto itr=st.begin(); itr!=st.end()&&itr->first<=lds[i].first-lds[i].second; ++itr) 
                nst[itr->first+lds[i].second] = itr->second + 1;
            for (auto pi : nst) st[pi.first] = max(st[pi.first], pi.second);
        }
        int res = 0;
        for (auto pi : st) res = max(res, pi.second);
        return res;
    }
};
