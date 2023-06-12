// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        int res = 0, li = 0, ri = n-1;
        while (ri >= li) {
            if (ri > li && people[li] + people[ri] <= limit) ++li, --ri;
            else --ri;
            ++res;
        }
        return res;
    }
};
