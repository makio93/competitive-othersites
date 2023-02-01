// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_set<char> sst;
        for (char ci : suits) sst.insert(ci);
        if ((int)(sst.size()) == 1) return string("Flush");
        unordered_map<int, int> vals;
        for (int val : ranks) vals[val]++;
        int mval = 0;
        for (auto pi : vals) mval = max(mval, pi.second);
        if (mval >= 3) return string("Three of a Kind");
        else if (mval == 2) return string("Pair");
        else return string("High Card");
    }
};
