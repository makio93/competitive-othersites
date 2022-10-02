// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size(), m = trainers.size();
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int id = 0;
        for (int i=0; i<m; ++i) {
            if (players[id] <= trainers[i]) {
                ++id;
                if (id >= n) break;
            }
        }
        return id;
    }
};
