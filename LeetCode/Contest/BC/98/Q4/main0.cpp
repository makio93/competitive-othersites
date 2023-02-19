// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class LazySegmentTree {
    int n;
    vector<int> node;
    vector<bool> lazy;
public:
    LazySegmentTree(int n_) : LazySegmentTree(vector<int>(n_)) {}
    LazySegmentTree(vector<int> v) {
        int n_ = v.size();
        n = 1;
        while (n < n_) n *= 2;
        node.resize(n*2-1, 0);
        lazy.resize(n*2-1, false);
        for (int i=0; i<n_; ++i) node[n+i-1] = v[i];
        for (int i=n-2; i>=0; --i) node[i] = node[i*2+1] + node[i*2+2];
    }
    void eval(int k, int l, int r) {
        if (lazy[k]) {
            node[k] = (r - l) - node[k];
            if (r-l > 1) {
                lazy[k*2+1] = !lazy[k*2+1];
                lazy[k*2+2] = !lazy[k*2+2];
            }
            lazy[k] = false;
        }
    }
    void update(int a, int b, int k=0, int l=0, int r=-1) {
        if (r == -1) r = n;
        eval(k, l, r);
        if (b<=l || r<=a) return;
        if (a<=l && r<=b) {
            lazy[k] = !lazy[k];
            eval(k, l, r);
        }
        else {
            update(a, b, k*2+1, l, (l+r)/2);
            update(a, b, k*2+2, (l+r)/2, r);
            node[k] = node[k*2+1] + node[k*2+2];
        }
    }
    int getSum(int a, int b, int k=0, int l=0, int r=-1) {
        if (r == -1) r = n;
        if (b<=l || r<=a) return 0;
        eval(k, l, r);
        if (a<=l && r<=b) return node[k];
        int vl = getSum(a, b, k*2+1, l, (l+r)/2);
        int vr = getSum(a, b, k*2+2, (l+r)/2, r);
        return vl + vr;
    }
};
class Solution {
public:
    vector<ll> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size(), m = queries.size();
        vector<ll> res;
        ll sum = accumulate(nums2.begin(), nums2.end(), 0LL);
        LazySegmentTree lst(nums1);
        for (int i=0; i<m; ++i) {
            if (queries[i][0] == 1) lst.update(queries[i][1], queries[i][2]+1);
            else if (queries[i][0] == 2) sum += lst.getSum(0, n) * (ll)queries[i][1];
            else res.push_back(sum);
        }
        return res;
    }
};
