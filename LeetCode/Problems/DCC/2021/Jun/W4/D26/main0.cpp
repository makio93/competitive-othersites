#include <bits/stdc++.h>
using namespace std;

// 自力AC

struct BIT {
    int n;
    vector<int> d;
    BIT(int n=0) : n(n), d(n+1) {}
    void add(int i, int x=1) {
        for (i++; i<=n; i+=i&-i) {
            d[i] += x;
        }
    }
    int sum(int i) {
        int x = 0;
        for (i++; i; i-=i&-i) {
            x += d[i];
        }
        return x;
    }
    int sum(int l, int r) {
        return sum(r-1) - sum(l-1);
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> vids(n);
        for (int i=0; i<n; ++i) vids[i] = { nums[i], i };
        sort(vids.begin(), vids.end());
        BIT bcnt(n);
        vector<int> res(n);
        for (int i=0; i<n; ++i) {
            res[vids[i].second] = i - bcnt.sum(0, vids[i].second);
            bcnt.add(vids[i].second);
        }
        return res;
    }
};
