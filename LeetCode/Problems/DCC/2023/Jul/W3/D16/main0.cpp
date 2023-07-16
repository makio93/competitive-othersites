// 自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size(), m = people.size();
        unordered_map<string, int> skill_ids;
        for (int i=0; i<n; ++i) skill_ids[req_skills[i]] = i;
        vector<int> people_skills(m);
        for (int i=0; i<m; ++i) for (const string& si : people[i]) if (skill_ids.find(si) != skill_ids.end()) people_skills[i] |= 1 << skill_ids[si];
        vector<ll> dp(1<<n, -1LL);
        dp[0] = 0LL;
        for (int i=0; i<m; ++i) {
            vector<ll> ndp = dp;
            for (int j=0; j<1<<n; ++j) if (dp[j] != -1LL) {
                int tj = j | people_skills[i];
                ll vb = dp[j] | (1LL << i);
                if (ndp[tj] == -1LL) ndp[tj] = vb;
                else if (__builtin_popcountll(vb) < __builtin_popcountll(ndp[tj])) ndp[tj] = vb;
            }
            swap(ndp, dp);
        }
        vector<int> res;
        for (int i=0; i<m; ++i) if (dp[(1<<n)-1]>>i&1LL) res.push_back(i);
        return res;
    }
};
