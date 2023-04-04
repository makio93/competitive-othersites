// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size(), mx = *max_element(potions.begin(), potions.end());
        vector<int> pcnt(mx+2);
        for (int i=0; i<m; ++i) pcnt[potions[i]]++;
        for (int i=mx; i>=0; --i) pcnt[i] += pcnt[i+1];
        vector<int> pairs(n);
        for (int i=0; i<n; ++i) pairs[i] = pcnt[(int)min((long long)mx+1, (success+spells[i]-1)/spells[i])];
        return pairs;
    }
};
