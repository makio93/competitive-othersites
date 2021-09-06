#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = releaseTimes.size();
        pair<int, char> res = { releaseTimes.front(), keysPressed.front() };
        for (int i=1; i<n; ++i) res = max(res, { releaseTimes[i]-releaseTimes[i-1], keysPressed[i] });
        return res.second;
    }
};
