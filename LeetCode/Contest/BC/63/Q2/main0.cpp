#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
    string tar = "AB";
public:
    bool winnerOfGame(string colors) {
        int n = colors.length();
        vector<pair<char, int>> run;
        run.emplace_back(colors.front(), 1);
        for (int i=1; i<n; ++i) {
            if (colors[i] == run.back().first) run.back().second++;
            else run.emplace_back(colors[i], 1);
        }
        vector<int> cnt(2);
        for (auto pi : run) for (int i=0; i<2; ++i) 
            if (tar[i] == pi.first) cnt[i] += max(0, pi.second-2);
        return (cnt[0] > cnt[1]);
    }
};
