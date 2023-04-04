// 解説AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size(), res = 0, ri = n - 1;
        sort(people.begin(), people.end(), greater<int>());
        while (res <= ri) {
            if (res<ri && people[res]+people[ri]<=limit) --ri;
            ++res;
        }
        return res;
    }
};
