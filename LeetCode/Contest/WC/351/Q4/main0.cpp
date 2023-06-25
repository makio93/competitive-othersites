// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> plst = positions;
        sort(plst.begin(), plst.end());
        for (int i=0; i<n; ++i) positions[i] = lower_bound(plst.begin(), plst.end(), positions[i]) - plst.begin();
        vector<tuple<int, char, int, int>> rlst(n);
        for (int i=0; i<n; ++i) rlst[i] = { positions[i], directions[i], healths[i], i };
        sort(rlst.begin(), rlst.end());
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> lpq;
        priority_queue<tuple<int, int, int>> rpq;
        vector<pair<int, int>> pres;
        for (int i=n-1; i>=0; --i) {
            if (get<1>(rlst[i]) == 'L') lpq.emplace(get<0>(rlst[i]), get<2>(rlst[i]), get<3>(rlst[i]));
            else rpq.emplace(get<0>(rlst[i]), get<2>(rlst[i]), get<3>(rlst[i]));
            while (!lpq.empty() && !rpq.empty()) {
                if (get<1>(rpq.top()) < get<1>(lpq.top())) {
                    rpq.pop();
                    auto tval = lpq.top(); lpq.pop();
                    lpq.emplace(get<0>(tval), get<1>(tval)-1, get<2>(tval));
                }
                else if (get<1>(rpq.top()) > get<1>(lpq.top())) {
                    lpq.pop();
                    auto tval = rpq.top(); rpq.pop();
                    rpq.emplace(get<0>(tval), get<1>(tval)-1, get<2>(tval));
                }
                else {
                    lpq.pop();
                    rpq.pop();
                }
            }
            if (lpq.empty()) {
                while (!rpq.empty()) {
                    pres.emplace_back(get<2>(rpq.top()), get<1>(rpq.top()));
                    rpq.pop();
                }
            }
        }
        while (!lpq.empty()) {
            pres.emplace_back(get<2>(lpq.top()), get<1>(lpq.top()));
            lpq.pop();
        }
        sort(pres.begin(), pres.end());
        vector<int> res;
        for (const auto& pi : pres) res.push_back(pi.second);
        return res;
    }
};
