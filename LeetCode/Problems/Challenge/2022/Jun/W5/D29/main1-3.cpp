// 解説AC3

#include <bits/stdc++.h>
using namespace std;

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
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(), [](auto& vl, auto& vr) -> bool {
            return vl[0] != vr[0] ? vl[0] < vr[0] : vl[1] > vr[1];
        });
        BIT<int> pcnt(n+1);
        for (int i=0; i<n; ++i) pcnt.add(i);
        vector<vector<int>> res(n);
        for (auto& vi : people) {
            int li = 0, ri = n;
            while (ri-li > 1) {
                int ci = li + (ri-li) / 2, mval = pcnt.sum(0, ci);
                if (mval > vi[1]) ri = ci;
                else li = ci;
            }
            res[li] = vi;
            pcnt.add(li, -1);
        }
        return res;
    }
};
