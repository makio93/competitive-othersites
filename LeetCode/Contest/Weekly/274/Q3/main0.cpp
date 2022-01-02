#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        sort(asteroids.begin(), asteroids.end());
        ll val = mass;
        for (int i=0; i<n; ++i) {
            if (val >= asteroids[i]) val += asteroids[i];
            else return false;
        }
        return true;
    }
};
