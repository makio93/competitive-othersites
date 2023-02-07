// 学習1回目,解説AC3

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> bit;
    void add(int p, int x) { for (++p; p<(int)(bit.size()); p+=p&-p) bit[p] += x; }
    int sum(int p) {
        int val = 0;
        for (++p; p>0; p-=p&-p) val += bit[p];
        return val;
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(), [](auto& li, auto& ri) -> bool {
            return li[0] != ri[0] ? li[0] < ri[0] : li[1] > ri[1];
        });
        vector<vector<int>> res(n);
        int two = 1;
        while (two < n) two *= 2;
        bit.assign(two+1, 0);
        for (int i=0; i<n; ++i) add(i, 1);
        for (int i=0; i<n; ++i) {
            int li = -1, ri = n-1;
            while (ri-li > 1) {
                int ci = ri - (ri-li) / 2;
                if (sum(ci) >= people[i][1]+1) ri = ci;
                else li = ci;
            }
            res[ri] = people[i];
            add(ri, -1);
        }
        return res;
    }
};
