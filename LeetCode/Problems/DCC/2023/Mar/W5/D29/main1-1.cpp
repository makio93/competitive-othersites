// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> memo(n+1, vector<int>(n+1, -1));
        auto f = [&](auto& f, int id=0, int ti=1) -> int {
            if (memo[id][ti-1] != -1) return memo[id][ti-1];
            if (id == n) return memo[id][ti-1] = 0;
            return memo[id][ti-1] = max(satisfaction[id]*ti+f(f,id+1,ti+1), f(f,id+1,ti));
        };
        return f(f);
    }
};
