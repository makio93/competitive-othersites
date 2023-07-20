// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> res;
        for (int i=0; i<n; ++i) {
            bool fire = false;
            while (!res.empty() && res.back()>0 && !fire && asteroids[i]<0) {
                if (abs(asteroids[i]) <= res.back()) fire = true;
                if (res.back() <= abs(asteroids[i])) res.pop_back();
            }
            if (!fire) res.push_back(asteroids[i]);
        }
        return res;
    }
};
