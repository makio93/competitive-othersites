#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
    long long gcd(long long a, long long b) { return (b ? gcd(b, a%b) : a); }
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        map<pair<int, int>, int> pcnt;
        for (int i=0; i<n; ++i) {
            int d = (int)gcd(rectangles[i][0], rectangles[i][1]);
            pcnt[{rectangles[i][0]/d,rectangles[i][1]/d}]++;
        }
        long long res = 0;
        for (auto p : pcnt) res += (long long)p.second * (p.second-1) / 2;
        return res;
    }
};
