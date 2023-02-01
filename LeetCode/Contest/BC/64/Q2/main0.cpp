#include <bits/stdc++.h>
using namespace std;

<<<<<<< Updated upstream
// 本番AC
=======
// バチャ本番AC
>>>>>>> Stashed changes

class Solution {
    int INF = (int)(1.1e9);
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        vector<pair<int, int>> svlst(n);
        for (int i=0; i<n; ++i) svlst[i] = { events[i][0], events[i][2] };
        sort(svlst.begin(), svlst.end());
        map<int, int> mvals;
        mvals[INF] = 0;
        int pmval = 0;
        for (int i=n-1; i>=0; --i) {
            pmval = max(pmval, svlst[i].second);
            mvals[svlst[i].first] = pmval;
        }
        vector<pair<int, int>> evlst(n);
        for (int i=0; i<n; ++i) evlst[i] = { events[i][1], events[i][2] };
        sort(evlst.begin(), evlst.end());
        int res = 0;
        for (int i=0; i<n; ++i) {
            int nval = mvals.lower_bound(evlst[i].first+1)->second;
            res = max(res, evlst[i].second+nval);
        }
        return res;
    }
};
