#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size(), res = 0, nval = capacity;
        for (int i=0; i<n; ++i) {
            if (nval >= plants[i]) {
                ++res;
                nval -= plants[i];
            }
            else {
                res += i * 2 + 1;
                nval = capacity - plants[i];
            }
        }
        return res;
    }
};
