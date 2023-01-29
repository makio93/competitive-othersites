// 本番WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
    template<typename T>
    struct BIT {
        int n;
        vector<T> d;
        BIT(int n=0) : n(n), d(n+1) {}
        void add(int i, T x=1) {
            for (i++; i<=n; i+=i&-i) {
                d[i] += x;
            }
        }
        T sum(int i) {
            T x = 0;
            for (i++; i; i-=i&-i) {
                x += d[i];
            }
            return x;
        }
        T sum(int l, int r) {
            return sum(r-1) - sum(l-1);
        }
    };
public:
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        vector<BIT<ll>> vcnt(4, BIT<ll>(n));
        ll res = 0;
        for (int i=0; i<n; ++i) {
            vcnt[0].add(nums[i]-1);
            for (int j=1; j<4; ++j) vcnt[j].add(nums[i]-1, vcnt[j-1].sum(0, nums[i]-1));
            res += vcnt[3].sum(nums[i]-1, nums[i]);
        }
        return res;
    }
};
