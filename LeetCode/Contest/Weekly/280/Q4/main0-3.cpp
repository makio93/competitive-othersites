#include <bits/stdc++.h>
using namespace std;

// 本番WA3

class Solution {
    int n, slen, acnt, mcnt;
    vector<int> nvals;
    vector<vector<pair<int, int>>> vals;
    unordered_set<int> useds;
    int calc(int d, int val=0) {
        ++acnt;
        if ((int)(useds.size()) == n) return val;
        else if ((int)(useds.size())>n || ((int)(useds.size())<n&&d<=0)) return -1;
        else {
            int res = calc(d-1, val), add = 0;
            int tval = 0, cval = 0, aval = 0;
            if (acnt>mcnt && res!=-1) return res; 
            for (int i=0; i<n; ++i) if (useds.find(vals[d-1][i].second) == useds.end()) {
                tval = 0; cval = 0;
                add += (nvals[vals[d-1][i].second] & d);
                useds.insert(vals[d-1][i].second);
                int rval = calc(d-1, val+add);
                if (rval != -1) {
                    res = max(res, rval);
                    if (acnt > mcnt) return res;
                    tval = 1;
                }
                for (int j=i+1; j<n; ++j) if (useds.find(vals[d-1][j].second) == useds.end()) {
                    add += (nvals[vals[d-1][j].second] & d);
                    useds.insert(vals[d-1][j].second);
                    int rval2 = calc(d-1, val+add);
                    if (rval2 != -1) {
                        res = max(res, rval2);
                        if (acnt > mcnt) return res;
                        if (tval >= 1) ++cval;
                    }
                    useds.erase(vals[d-1][j].second);
                    add -= (nvals[vals[d-1][j].second] & d);
                    if (cval >= 3) break;
                }
                useds.erase(vals[d-1][i].second);
                add -= (nvals[vals[d-1][i].second] & d);
                if (cval >= 3) ++aval;
                if (aval >= 2) break;
            }
            return res;
        }
    }
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        n = nums.size(); slen = numSlots;
        nvals = nums;
        vals = vector<vector<pair<int, int>>>(slen);
        for (int i=1; i<=slen; ++i) {
            vector<pair<int, int>> tlst;
            for (int j=0; j<n; ++j) tlst.emplace_back((nums[j]&i), j);
            sort(tlst.rbegin(), tlst.rend());
            vals[i-1] = tlst;
        }
        sort(vals.rbegin(), vals.rend());
        acnt = 0; mcnt = (int)(3e6);
        return calc(slen);
    }
};

