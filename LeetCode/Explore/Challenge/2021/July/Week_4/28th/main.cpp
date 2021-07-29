#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> smd = { 0, 2, 1, 3 }, seeds;
        for (int m : smd) {
            for (int i=m; i<8; i+=4) {
                seeds.push_back(i);
                if (i+8 < 16) seeds.push_back(i+8);
            }
        }
        int sval = seeds.size();
        while (sval < n) {
            sval *= 4;
            vector<int> nseeds;
            for (int m : smd) for (int si : seeds) nseeds.push_back(4*si+m);
            swap(seeds, nseeds);
        }
        sval = seeds.size();
        for (int i=0; i<sval; ++i) seeds[i]++;
        vector<int> res;
        for (int si : seeds) if (si <= n) res.push_back(si);
        return res;
    }
};
