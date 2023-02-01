#include <bits/stdc++.h>
using namespace std;

// 本番WA2

class Solution {
    int n, slen;
    vector<int> vals;
    unordered_set<int> useds;
    int calc(int d, int val=0) {
        if ((int)(useds.size()) == n) return val;
        else if ((int)(useds.size())>n || ((int)(useds.size())<n&&d<=0)) return -1;
        else {
            int res = calc(d-1, val), add = 0;
            vector<int> unuseds;
            for (int i=0; i<n; ++i) if (useds.find(i) == useds.end()) unuseds.push_back(i);
            int m = unuseds.size();
            for (int i=0; i<m; ++i) {
                add += (vals[unuseds[i]] & d);
                useds.insert(unuseds[i]);
                int rval = calc(d-1, val+add);
                if (rval != -1) res = max(res, rval);
                for (int j=i+1; j<m; ++j) {
                    add += (vals[unuseds[j]] & d);
                    useds.insert(unuseds[j]);
                    int rval2 = calc(d-1, val+add);
                    if (rval2 != -1) res = max(res, rval2);
                    useds.erase(unuseds[j]);
                    add -= (vals[unuseds[j]] & d);
                }
                useds.erase(unuseds[i]);
                add -= (vals[unuseds[i]] & d);
            }
            return res;
        }
    }
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        n = nums.size(); slen = numSlots;
        vals = nums;
        return calc(slen);
    }
};
