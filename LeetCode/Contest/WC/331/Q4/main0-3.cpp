// 自力WA2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n = basket1.size();
        vector<int> vlst;
        for (int i=0; i<n; ++i) vlst.push_back(basket1[i]);
        for (int i=0; i<n; ++i) vlst.push_back(basket2[i]);
        sort(vlst.begin(), vlst.end());
        vlst.erase(unique(vlst.begin(), vlst.end()), vlst.end());
        int m = vlst.size();
        vector<int> vcnt1(m), vcnt2(m);
        for (int i=0; i<n; ++i) vcnt1[lower_bound(vlst.begin(),vlst.end(),basket1[i])-vlst.begin()]++;
        for (int i=0; i<n; ++i) vcnt2[lower_bound(vlst.begin(),vlst.end(),basket2[i])-vlst.begin()]++;
        bool ok = true;
        vector<int> slst1, slst2;
        for (int i=0; i<m; ++i) if (vcnt1[i] > vcnt2[i]) {
            if ((vcnt1[i]-vcnt2[i])%2 == 1) {
                ok = false;
                break;
            }
            for (int j=0; j<(vcnt1[i]-vcnt2[i])/2; ++j) slst1.push_back(vlst[i]);
        }
        if (!ok) return -1;
        for (int i=0; i<m; ++i) if (vcnt2[i] > vcnt1[i]) {
            if ((vcnt2[i]-vcnt1[i])%2 == 1) {
                ok = false;
                break;
            }
            for (int j=0; j<(vcnt2[i]-vcnt1[i])/2; ++j) slst2.push_back(vlst[i]);
        }
        if (!ok) return -1;
        sort(slst1.begin(), slst1.end());
        sort(slst2.begin(), slst2.end());
        ll res = 0;
        int slen = slst1.size(), id1 = 0, id2 = slen-1;
        while (id1<slen && slst1[id1]<slst2[id2]) {
            res += min(slst1[id1], slst2[id2]);
            ++id1; --id2;
        }
        id2 = 0;
        while (id1 < slen) {
            res += min(slst1[id1], slst2[id2]);
            ++id1; ++id2;
        }
        ll tres = 0;
        id1 = slen-1, id2 = 0;
        while (id2<slen && slst2[id2]<slst1[id1]) {
            tres += min(slst1[id1], slst2[id2]);
            ++id2; --id1;
        }
        id1 = 0;
        while (id2 < slen) {
            tres += min(slst2[id2], slst1[id1]);
            ++id1; ++id2;
        }
        res = min(res, tres);
        return res;
    }
};
