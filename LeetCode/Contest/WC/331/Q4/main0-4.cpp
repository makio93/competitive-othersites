// 自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll LINF = (ll)(1e18);
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n = basket1.size();
        vector<int> vlst;
        for (int i=0; i<n; ++i) vlst.push_back(basket1[i]);
        for (int i=0; i<n; ++i) vlst.push_back(basket2[i]);
        sort(vlst.begin(), vlst.end());
        vlst.erase(unique(vlst.begin(), vlst.end()), vlst.end());
        int m = vlst.size(), mval = vlst.front();
        vector<int> vcnt1(m), vcnt2(m);
        for (int i=0; i<n; ++i) vcnt1[lower_bound(vlst.begin(),vlst.end(),basket1[i])-vlst.begin()]++;
        for (int i=0; i<n; ++i) vcnt2[lower_bound(vlst.begin(),vlst.end(),basket2[i])-vlst.begin()]++;
        bool ok = true;
        int id1 = 0, id2 = m-1;
        ll res = 0;
        auto tcnt1 = vcnt1, tcnt2 = vcnt2;
        while (id1<m && id2>=0) {
            while (id1<m && tcnt1[id1]<=tcnt2[id1]) ++id1;
            while (id2>=0 && tcnt2[id2]<=tcnt1[id2]) --id2;
            if (id1 >= m) break;
            if ((tcnt1[id1]-tcnt2[id1])%2==1 || (tcnt2[id2]-tcnt1[id2])%2==1) {
                ok = false;
                break;
            }
            int tc = min((tcnt1[id1]-tcnt2[id1])/2, (tcnt2[id2]-tcnt1[id2])/2);
            res += tc * (ll)min({ vlst[id1], vlst[id2], mval*2 });
            tcnt1[id1] -= tc;
            tcnt2[id1] += tc;
            tcnt2[id2] -= tc;
            tcnt1[id2] += tc;
        }
        if (!ok) return -1;
        return res;
    }
};
