#include <bits/stdc++.h>
using namespace std;

// 解説AC2,Time:O(NlogN)

class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char, int> ccnt;
        for (char ci : s) ccnt[ci]++;
        sort(s.begin(), s.end(), [&](char a, char b){ return (ccnt[a]>ccnt[b] || (ccnt[a]==ccnt[b]&&a<b)); }); 
            // a,bをswapして,常に真偽が反転する必要がある
        return s;
    }
};
