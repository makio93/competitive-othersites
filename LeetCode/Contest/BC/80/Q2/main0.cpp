// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> res(n);
        for (int i=0; i<n; ++i) {
            res[i] = m - (lower_bound(potions.begin(), potions.end(), (success+spells[i]-1)/spells[i]) - potions.begin());
        }
        return res;
    }
};
