#include <bits/stdc++.h>
using namespace std;

// 本番WA

class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> lsum, rsum;
        for (int i=0; i<(1<<(n/2)); ++i) {
            int nsum = 0;
            for (int j=0; j<n/2; ++j) if ((i>>j)&1) nsum += nums[j];
            lsum.push_back(nsum);
        }
        for (int i=0; i<(1<<(n-n/2)); ++i) {
            int nsum = 0;
            for (int j=0; j<(n-n/2); ++j) if ((i>>j)&1) nsum += nums[n/2+j];
            rsum.push_back(nsum);
        }
        sort(lsum.begin(), lsum.end());
        sort(rsum.begin(), rsum.end());
        int n2 = lsum.size();
        int ans = (int)(1e9);
        for (int i=0; i<n2; ++i) {
            int tval = goal - lsum[i];
            auto itr = lower_bound(rsum.begin(), rsum.end(), tval);
            if (itr == rsum.end()) ans = min(ans, abs(goal-(*prev(itr)+lsum[i])));
            else if (itr == rsum.begin()) ans = ans = min(ans, abs(goal-(*itr+lsum[i])));
            else ans = min(ans, min(abs(goal-(*(prev(itr))+lsum[i])),abs(goal-(*itr+lsum[i]))));
        }
        return ans;
    }
};
