// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);

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

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        int lval = INF, rval = -INF;
        for (int i=0; i<n; ++i) {
            lval = min(lval, nums[i]);
            rval = max(rval, nums[i]);
        }
        BIT<int> bcnt(rval-lval+2);
        vector<int> res(n);
        for (int i=n-1; i>=0; --i) {
            res[i] = bcnt.sum(0, nums[i]-lval);
            bcnt.add(nums[i]-lval);
        }
        return res;
    }
};
