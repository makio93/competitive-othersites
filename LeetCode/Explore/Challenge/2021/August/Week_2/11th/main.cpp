#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size();
        map<int, int> pos, neg;
        for (int i=0; i<n; ++i) {
            if (arr[i] > 0) pos[arr[i]]++;
            else if (arr[i] < 0) neg[-arr[i]]++;
        }
        for (auto& p : pos) if (pos.find(p.first*2) != pos.end()) {
            int sub = min(p.second, pos[p.first*2]);
            p.second -= sub;
            pos[p.first*2] -= sub;
        }
        for (auto& p : neg) if (neg.find(p.first*2) != neg.end()) {
            int sub = min(p.second, neg[p.first*2]);
            neg[p.first*2] -= sub;
            p.second -= sub;
        }
        bool ok = true;
        for (auto p : pos) if (p.second != 0) ok = false;
        for (auto p : neg) if (p.second != 0) ok = false;
        return ok;
    }
};
