// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        multiset<int> plst;
        for (int i=0; i<n; ++i) plst.insert(people[i]);
        int res = 0;
        while (!plst.empty()) {
            ++res;
            int val = *prev(plst.end());
            plst.erase(prev(plst.end()));
            auto itr = plst.upper_bound(limit-val);
            if (itr != plst.begin()) plst.erase(prev(itr));
        }
        return res;
    }
};
