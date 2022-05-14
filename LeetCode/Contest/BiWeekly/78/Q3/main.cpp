// 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int n = tiles.size();
        map<int, int> tlst;
        for (int i=0; i<n; ++i) tlst[tiles[i][0]] = tiles[i][1] - tiles[i][0] + 1;
        auto ritr = tlst.begin();
        int res = 0, val = 0;
        for (auto itr=tlst.begin(); itr!=tlst.end(); ++itr) {
            while (itr->first+carpetLen>ritr->first+ritr->second-1 && ritr!=tlst.end()) {
                val += ritr->second;
                ++ritr;
            }
            int tval = (ritr!=tlst.end()) ? max(0, itr->first+carpetLen-ritr->first) : 0;
            res = max(res, val+tval);
            val -= itr->second;
        }
        return res;
    }
};
