// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> pairs(n);
        for (int i=0; i<n; ++i) pairs[i] = potions.end() - lower_bound(potions.begin(), potions.end(), (success+spells[i]-1)/spells[i]);
        return pairs;
    }
};
