// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(), [&](int li, int ri){
            return capacity[li] - rocks[li] < capacity[ri] - rocks[ri];
        });
        for (int i=0; i<n; ++i) {
            int add = min(capacity[ids[i]]-rocks[ids[i]], additionalRocks);
            rocks[ids[i]] += add;
            additionalRocks -= add;
            if (additionalRocks == 0) break;
        }
        int res = 0;
        for (int i=0; i<n; ++i) if (capacity[i] == rocks[i]) ++res;
        return res;
    }
};
