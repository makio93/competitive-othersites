// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int li = -1, res = 0;
        for (int i=0; i<n; ++i) if (seats[i] == 1) {
            if (li == -1) res = i;
            else res = max(res, (i-li)/2);
            li = i;
        }
        res = max(res, n-1-li);
        return res;
    }
};
