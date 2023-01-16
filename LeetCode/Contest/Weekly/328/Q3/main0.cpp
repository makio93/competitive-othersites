// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> tlst = nums;
        sort(tlst.begin(), tlst.end());
        tlst.erase(unique(tlst.begin(), tlst.end()), tlst.end());
        for (int i=0; i<n; ++i) nums[i] = lower_bound(tlst.begin(), tlst.end(), nums[i]) - tlst.begin();
        vector<int> vcnt(n);
        long long res = 0, kcnt = 0;
        int ri = 0;
        for (int i=0; i<n; ++i) {
            while (ri<n && kcnt<k) {
                kcnt -= (long long)vcnt[nums[ri]] * (vcnt[nums[ri]]-1) / 2;
                vcnt[nums[ri]]++;
                kcnt += (long long)vcnt[nums[ri]] * (vcnt[nums[ri]]-1) / 2;
                ++ri;
            }
            if (kcnt < k) break;
            if (kcnt >= k) res += n - ri + 1;
            kcnt -= (long long)vcnt[nums[i]] * (vcnt[nums[i]]-1) / 2;
            vcnt[nums[i]]--;
            kcnt += (long long)vcnt[nums[i]] * (vcnt[nums[i]]-1) / 2;
        }
        return res;
    }
};
